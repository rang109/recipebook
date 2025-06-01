from django.db import models

class Ingredient(models.Model):
    ingredientID = models.CharField(max_length=20, primary_key=True)
    ingredientName = models.CharField(max_length=50)
    measure = models.FloatField()
    unit = models.CharField(max_length=10)

    def __str__(self):
        return self.ingredientName


class Recipe(models.Model):
    recipeID = models.CharField(max_length=20, primary_key=True)
    cuisineName = models.CharField(max_length=50)
    categoryName = models.CharField(max_length=20)
    recipeName = models.CharField(max_length=50)
    duration = models.IntegerField()
    serving = models.IntegerField()
    description = models.TextField()
    procedure = models.TextField()
    img_url = models.URLField(blank=True, null=True)
    favorite = models.BooleanField(default=False)
    date = models.DateField()
    ingredients = models.ManyToManyField(Ingredient, through='Have')

    def __str__(self):
        return self.recipeName


class Have(models.Model):
    recipe = models.ForeignKey(Recipe, on_delete=models.CASCADE)
    ingredient = models.ForeignKey(Ingredient, on_delete=models.CASCADE)
    quantity = models.IntegerField()

    class Meta:
        unique_together = ('recipe', 'ingredient')
