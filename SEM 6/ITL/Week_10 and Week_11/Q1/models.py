from django.db import models

class Category(models.Model):
    name = models.CharField(max_length=100)
    visits = models.PositiveIntegerField(default=0)
    likes = models.PositiveIntegerField(default=0)

class Page(models.Model):
    category = models.ForeignKey(Category, on_delete=models.CASCADE)
    title = models.CharField(max_length=200)
    url = models.URLField()
    views = models.PositiveIntegerField(default=0)
