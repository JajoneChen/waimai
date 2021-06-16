from django.http import HttpResponse
from django.shortcuts import render
import sqlite3


# Create your views here.

def main_view(request):
    return render(request, 'main.html')


def show_view(request):
    x = request.GET.get('choice')
    return HttpResponse(x)
