#include "RecipeDB.h"
#include <iostream>

RecipeDB::RecipeDB() : db(nullptr) {}

RecipeDB::~RecipeDB() {
    close();
}

bool RecipeDB::open(const std::string& dbPath) {
    if (sqlite3_open(dbPath.c_str(), &db) != SQLITE_OK) {
        logError("Failed to open database");
        return false;
    }
    
    // Enable foreign keys
    sqlite3_exec(db, "PRAGMA foreign_keys = ON;", nullptr, nullptr, nullptr);
    return true;
}

void RecipeDB::close() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
    }
}

int RecipeDB::addRecipe(const Recipe& recipe) {
    sqlite3_stmt* stmt;
    const std::string sql = "INSERT INTO Recipe (cuisineName, categoryName, recipeName, "
                          "description, procedure, img_url, favorite) "
                          "VALUES (?, ?, ?, ?, ?, ?, ?);";
    
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        logError("Failed to prepare recipe insert");
        return -1;
    }
    
    // Binding parameters
    sqlite3_bind_text(stmt, 1, recipe.cuisine.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, recipe.category.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, recipe.name.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, recipe.description.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, recipe.procedure.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 6, recipe.img_url.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 7, recipe.favorite ? 1 : 0);
    
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        logError("Failed to execute recipe insert");
        sqlite3_finalize(stmt);
        return -1;
    }
    
    int recipeID = sqlite3_last_insert_rowid(db);
    sqlite3_finalize(stmt);
    
    // Add ingredients
    for (const auto& [ingredient, quantity] : recipe.ingredients) {
        linkIngredientToRecipe(recipeID, ingredient.ingredientID, quantity);
    }
    
    return recipeID;
}

// ... (implement other methods following the same pattern)

void RecipeDB::logError(const std::string& message) {
    std::cerr << "Database Error: " << message;
    if (db) {
        std::cerr << " (" << sqlite3_errmsg(db) << ")";
    }
    std::cerr << std::endl;
}