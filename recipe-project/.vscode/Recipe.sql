CREATE TABLE Recipe (
    recipeID INTEGER PRIMARY KEY AUTOINCREMENT,
    cuisineName TEXT NOT NULL,
    categoryName TEXT NOT NULL,
    recipeName TEXT NOT NULL,
    description TEXT,
    process TEXT,
    img_url TEXT,
    favorite BOOLEAN DEFAULT 0,
    date TEXT DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE Ingredients (
    ingredientID INTEGER PRIMARY KEY AUTOINCREMENT,
    ingredientName TEXT NOT NULL,
    measure REAL,
    unit TEXT
);

CREATE TABLE have (
    recipeID INTEGER,
    ingredientID INTEGER,
    quantity REAL,
    PRIMARY KEY (recipeID, ingredientID),
    FOREIGN KEY (recipeID) REFERENCES Recipe(recipeID),
    FOREIGN KEY (ingredientID) REFERENCES Ingredients(ingredientID)
);
