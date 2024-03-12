from django.urls import path 
from . import views
 
urlpatterns = [
	path('',views.firstPage,name='firstPage'),
	path('firstPage/',views.firstPage,name='firstPage'),
	path('secondPage/',views.secondPage,name='secondPage'),
]
