<script setup lang="ts">
</script>

<template>
  <div class="flex flex-col bg-[#626F47] md:flex-row h-auto md:h-screen">
  <img src="/src/assets/pictures/home-img.png" alt="home-img" className="w-full md:w-1/2 h-64 md:h-full object-cover object-left">

  <div class="w-full md:w-1/2 flex flex-col justify-center items-center gap-8 p-2 md:p-10 text-center">
    <div class="flex flex-col items-center gap-6 lg:gap-15 text-[#F5ECD5] custom-text-shadow">
      <p class="font-pacifico text-4xl md:text-5xl lg:text-7xl">My Recipe Book</p>
      <p class="text-center">Store, manage, and track your favorite recipes. Discover new dishes, save family favorites, and create your personal 
        digital cookbook — all in one place. Whether you're meal-planning or experimenting with something new, 
        your kitchen companion is here to help.</p>
    </div>

    <div class="flex flex-col sm:flex-row gap-4 w-full sm:w-auto justify-center items-center">
      <RouterLink to="/recipes">
      <div class="flex flex-col bg-[#F5ECD5] text-[#626F47] items-center font-regular py-2 px-4 rounded shadow">
        <Utensils color="#F0BB78"/>
        <img src="/src/assets/icons/utensil-icon-orange.svg" alt="">
        Recipes
      </div>
      </RouterLink>
      <RouterLink to="/add-recipe">
        <div class="flex flex-col bg-[#F0BB78] text-[#626F47] items-center font-regular py-2 px-4 rounded shadow">
          <Utensils color="#F0BB78"/>
          <img src="/src/assets/icons/add-recipe-icon-light.svg" alt="">
          Add Recipes
        </div>
      </RouterLink>
      </div>
  </div>
  </div>
</template>

