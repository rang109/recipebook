import { createRouter, createWebHistory } from 'vue-router'
import HomeView from '../views/HomeView.vue'

const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [
    {
      path: '/',
      name: 'home',
      component: HomeView,
    },
    {
      path: '/recipes',
      name: 'recipe list',
      component: () => import('../views/RecipeView.vue'),
    },
    {
      path: '/add-recipe',
      name: 'add recipe form',
      component: () => import('../views/AddRecipeView.vue'),
    },
    {
      path: '/recipe/:id',
      name: 'recipe details',
      component: () => import('../views/RecipeDetailsView.vue'),
    },
    {
      path: '/favorites',
      name: 'favorites',
      component: () => import('../views/FavoritesView.vue'),
    },
    {
      path: '/edit-recipe',
      name: 'edit recipe',
      component: () => import('../views/EditRecipeView.vue'),
    },
  ],
})

export default router
