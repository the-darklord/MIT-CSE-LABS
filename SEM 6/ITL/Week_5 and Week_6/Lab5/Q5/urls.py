from django.urls import re_path as url
from . import views

urlpatterns = [
    url(r'',views.home,name='home'),
    url(r'home/',views.home,name='home'),
    url(r'metadata/',views.metadata,name='metadata'),
    url(r'publisher/',views.publisher,name='publisher'),
    url(r'reviews/',views.reviews,name='reviews'),
]
