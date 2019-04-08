from django.contrib import admin
from .models import Athlete, Run, Location, RunSplit

admin.site.register( Athlete)
admin.site.register( Run)
admin.site.register( Location)
admin.site.register( RunSplit)