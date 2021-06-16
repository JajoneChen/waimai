from django.db import models


# Create your models here.
class Info(models.Model):
    report_title = models.CharField(max_length=100)
    report_reporter = models.CharField(max_length=100)
    report_date = models.CharField(max_length=100)
    report_place = models.CharField(max_length=100)
    university = models.CharField(max_length=20)
    link = models.CharField(max_length=100)
