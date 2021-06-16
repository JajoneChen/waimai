from django.urls import path
from . import views

urlpatterns = [
    path('', views.main_view),
    path('index/', views.show_view)
]