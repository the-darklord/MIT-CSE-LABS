from django.urls import path
from . import views

urlpatterns = [
    path('',views.index,name='index'),
    path('categories/', views.addCategory, name='addCategory'),
    path('pages/', views.addPage, name='addPage'),
]
