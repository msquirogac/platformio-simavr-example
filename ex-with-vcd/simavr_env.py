# Credits to MaslowCNC for the original code
from SCons.Script import ARGUMENTS, AlwaysBuild

Import('env')

# Dump construction environment
#print(env.Dump())

# Don't try to upload the firmware
env.Replace(UPLOADHEXCMD="echo Upload is not supported for ${PIOENV}. Skipping")

pioenv = env.get("PIOENV")
progname = env.get("PROGNAME")
brdmcu = env.get("BOARD_MCU")
brdfcpu = env.get("BOARD_F_CPU")

def simulate_callback(*args, **kwargs):
    env.Execute("simavr -g -m " + brdmcu + " -f " + brdfcpu + " .pio/build/" + pioenv + "/" + progname + ".elf")

AlwaysBuild(env.Alias("simulate", "", simulate_callback))