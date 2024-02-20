"""
Lab5 URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/2.1/topics/http/urls/

Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""

# Uncomment next two lines to enable admin:
from django.contrib import admin
from django.urls import path,include
from django.urls import re_path as url
from django.conf.urls.static import static
from django.conf import settings
from . import views 

urlpatterns = [
    # Uncomment the next line to enable the admin:
    path('admin/', admin.site.urls),
    path('FormApp/', include('FormApp.urls')),
    path('Q1/',include('Q1.urls')),
    path('Q2/',include('Q2.urls')),
    path('Q3/',include('Q3.urls')),
    path('Q4/',include('Q4.urls')),
    path('Q5/',include('Q5.urls')),
    url(r'^$',views.hello,name='hello'),
    url(r'index/', views.index, name='index'),
    path('',views.Calendar,name='Calendar'),
    url(r'^(?P<year>[0-9]{4})/(?P<month>0?[1-9]|1[0-2])/',views.Calendar,name='Calendar'),
]

urlpatterns += static(settings.STATIC_URL, document_root=settings.STATIC_ROOT)
