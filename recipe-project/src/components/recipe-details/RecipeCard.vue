<!-- create a card for each recipe -->

<script setup lang="ts">
import { defineProps, defineEmits } from 'vue'
const props = defineProps<{
    id: string
    recipe_name: string
    cuisine: string
    category: string
    image: string
    favorite: boolean
}>()

const emit = defineEmits(['toggle-favorite'])

function toggleFavorite() {
    emit('toggle-favorite', props.id)
}
</script>

<template>
    <div class="flex flex-col flex-end bg-[#F0BB78] w-[25rem] p-5 rounded-2xl">
        <RouterLink :to="`/recipe/${id}`" className="block mb-5">
            <img :src="image" alt="" class="">
        </RouterLink>

        <div class="flex flex-row text-[#626F47] justify-between">
            <div class="flex flex-col">
                <p class="font-bold text-2xl">{{ recipe_name }}</p>
                <p class="">{{ cuisine }} | {{ category }}</p>
            </div>
            
            <div class="flex flex-row items-center gap-1">
                <img :src="favorite ? '/src/assets/icons/heart-icon-filled.svg' : '/src/assets/icons/heart-icon-outlined.svg'" 
                    alt="" 
                    class="w-9 h-9 cursor-pointer"
                    @click.stop="toggleFavorite"
                >
                <RouterLink to="/edit-recipe">
                    <img src="/src/assets/icons/edit-icon.svg" alt="" class="w-10 h-10">
                </RouterLink>
                <img src="/src/assets/icons/delete-icon.svg" alt="" class="w-10 h-10">
            </div>
        </div>
    </div>
</template>