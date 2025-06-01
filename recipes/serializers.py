from rest_framework import serializers
from .models import Recipe, Ingredient, Have

class RecipeSerializer(serializers.ModelSerializer):
    class Meta:
        model = Recipe
        fields = '__all__'

class IngredientSerializer(serializers.ModelSerializer):
    class Meta:
        model = Ingredient
        fields = '__all__'

class HaveSerializer(serializers.ModelSerializer):
    class Meta:
        model = Have
        fields = '__all__'
