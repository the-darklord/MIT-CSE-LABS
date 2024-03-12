from django.contrib import admin

# Register your models here.

import site
from .models import BlogPost
from . import models

class BlogPostAdmin(admin.ModelAdmin): 
    list_display = ('title', 'timestamp') 
admin.site.register(models.BlogPost,BlogPostAdmin) 