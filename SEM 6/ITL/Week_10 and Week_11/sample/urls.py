from django.urls import include,path
from . import views

urlpatterns = [
    path('',views.archive,name='archive'),
    path('create/',views.createBlogPost,name='createBlogPost'),
]
