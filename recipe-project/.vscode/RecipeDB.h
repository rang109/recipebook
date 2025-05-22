#ifndef RECIPE_DB_H
#define RECIPE_DB_H

#include <string>
#include <vector>
#include <sqlite3.h>

struct Ingredient {
    int ingredientID;
    std::string name;
    double measure;
    std::string unit;
};

struct Recipe {
    int recipeID;
    std::string cuisine;
    std::string category;
    std::string name;
    std::string description;
    std::string procedure;
    std::string img_url;
    bool favorite;
    std::string date;
    std::vector<std::pair<Ingredient, double>> ingredients;
};

class RecipeDB {
public:
    RecipeDB();
    ~RecipeDB();

    bool open(const std::string& dbPath);
    void close();
    
    // Recipe operations
    int addRecipe(const Recipe& recipe);
    bool deleteRecipe(int recipeID);
    bool updateRecipe(const Recipe& recipe);
    std::vector<Recipe> getAllRecipes();
    std::vector<Recipe> getRecipesByCuisine(const std::string& cuisine);
    std::vector<Recipe> getFavoriteRecipes();
    
    // Ingredient operations
    int addIngredient(const Ingredient& ingredient);
    bool linkIngredientToRecipe(int recipeID, int ingredientID, double quantity);
    std::vector<Ingredient> getRecipeIngredients(int recipeID);

private:
    sqlite3* db;
    void logError(const std::string& message);
};

#endif // RECIPE_DB_H