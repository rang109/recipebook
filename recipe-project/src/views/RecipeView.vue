<!-- generate all the cards created for each recipe -->

<script setup>
import RecipeCard from '@/components/recipe-details/RecipeCard.vue';
import { recipes as initialRecipes } from "@/stores/recipe"
import { ref } from 'vue'

const recipes = ref([...initialRecipes])
const successMessage = ref('')
const messageTimeout = ref(null)

function toggleFavorite(id) {
  const recipe = recipes.value.find(r => r.id === id)
  if (recipe) {
    recipe.favorite = !recipe.favorite

    // Show message
    successMessage.value = recipe.favorite
      ? `"${recipe.recipe_name}" added to favorites!`
      : `"${recipe.recipe_name}" removed from favorites!`

    // Clear message after 3 seconds
    clearTimeout(messageTimeout.value)
    messageTimeout.value = setTimeout(() => {
      successMessage.value = ''
    }, 3000)
  }
}

console.log(recipes)
</script>

<template>
  <div class="bg-[#F5ECD5] min-h-screen p-10">
    <div v-if="successMessage" class="bg-green-100 text-green-800 p-3 rounded mb-4 transition-opacity duration-300">
      {{ successMessage }}
    </div>
    <div class="flex flex-row justify-between items-center">
      <p class="font-pacifico text-6xl text-[#626F47] custom-text-shadow">Recipes</p>
      <div class="flex flex-row gap-3 text-[#626F47]">
        <RouterLink to="/favorites" class="flex flex-row p-2 gap-2 bg-[#F0BB78] rounded button-box-shadow">
          <img src="/src/assets/icons/heart-icon-filled.svg" alt="" class="w-5 h-5">
          My Favorites
        </RouterLink>
        <RouterLink to="/add-recipe" class="flex flex-row p-2 gap-2 bg-[#F0BB78] rounded button-box-shadow">
          <img src="/src/assets/icons/add-recipe-icon-dark.svg" alt="" class="w-5 h-5">
          Add Recipe
        </RouterLink>
      </div>
    </div>
    <div class="grid grid-cols-1 sm:grid-cols-1 md:grid-cols-4 mt-10 gap-10">
      <RecipeCard
        v-for = "recipe in recipes"
        :key="recipe.id"
        :id="recipe.id"
        :recipe_name="recipe.recipe_name"
        :cuisine="recipe.cuisine"
        :category="recipe.category"
        :image="recipe.image"
        v-bind="recipe"
        @toggle-favorite="toggleFavorite"
      />
  </div>
  </div>
</template>
