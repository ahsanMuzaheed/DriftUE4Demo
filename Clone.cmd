@echo off
set repo=git@github.com:dgnorth
set pluginsdir=Plugins/Drift
set sourcedir=Source/Drift

git submodule add %repo%/DriftUE4Base.git %sourcedir%
git submodule add %repo%/DriftUE4Analytics.git %pluginsdir%/DriftAnalytics
git submodule add %repo%/DriftUE4GameCenter.git %pluginsdir%/DriftGameCenter
git submodule add %repo%/DriftUE4GooglePlay.git %pluginsdir%/DriftGooglePlay
git submodule add %repo%/DriftUE4Oculus.git %pluginsdir%/DriftOculus
git submodule add %repo%/DriftUE4Steam.git %pluginsdir%/DriftSteam
git submodule add %repo%/OnlineSubsystemDrift.git %pluginsdir%/OnlineSubsystemDrift

