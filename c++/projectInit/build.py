import os
import subprocess

if not os.path.isdir("build"):
    os.mkdir("build")

os.chdir("build")
subprocess.run(["cmake", ".."], check=True)
subprocess.run(["cmake", "--build", "."], check=True)
subprocess.run(["sudo", "cp", "src/Main/Main", "/usr/bin/ProjectInit"], check=True)