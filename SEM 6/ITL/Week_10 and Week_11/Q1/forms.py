from django import forms
from .models import Category, Page

class CategoryForm(forms.ModelForm):
    class Meta:
        model = Category
        fields = ['name', 'visits', 'likes']

class PageForm(forms.ModelForm):
    class Meta:
        model = Page
        fields = ['category', 'title', 'url', 'views']
