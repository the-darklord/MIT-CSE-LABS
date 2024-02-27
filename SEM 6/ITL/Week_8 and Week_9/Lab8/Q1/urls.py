from django.urls import path
from . import views 

urlpatterns = [
    path('',views.home,name='home'),
    path('display/',views.display,name='display'),
]

