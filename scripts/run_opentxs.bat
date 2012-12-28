@echo off

set START_DIR="%cd%"

cd /D %~dp0..\

ot.exe scripts\opentxs

cd /D %START_DIR%