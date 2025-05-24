<script setup>
import { useRoute } from 'vue-router';
import { recipes } from '@/stores/recipe';

const route = useRoute()
const recipeId = String(route.params.id)
const recipe = recipes.find(r => r.id === recipeId)

console.log(recipes)
</script>

<template>
    <div v-if="recipe" class="p-6">
        <p class="text-center">{{ recipe.recipe_name }}</p>
    </div>

    <div v-else class="p-6 text-red-700">
        Recipe not found
    </div>
</template>