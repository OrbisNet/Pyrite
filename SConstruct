import os
from SCons.Script import *
from SCons.Environment import Environment
from SCons.Defaults import Delete, Mkdir
from glob import glob as Glob

TOOLCHAIN = os.environ.get('OO_PS4_TOOLCHAIN')
GH_SDK = os.environ.get("GOLDHEN_SDK")

env = Environment(tools=['gcc', 'g++','ar'], ENV=os.environ)

env.Replace(CC='clang')
env.Replace(AR='llvm-ar')
env.Replace(CXX='clang++')

pyrite_base_flags = [
    '--target=x86_64-pc-freebsd12-elf',
    '-fPIC',
    '-funwind-tables',
    '-c',
    '-isysroot', TOOLCHAIN,
    '-I' + os.path.join(TOOLCHAIN, 'include'),
    '-I' + os.path.join(TOOLCHAIN, 'include/bits'),
    '-I' + os.path.join(TOOLCHAIN, 'include/sys'),
    '-I' + os.path.join(GH_SDK, 'include'),
    '-D__PRX_BUILD__',
    '-Wall',
    "-fcolor-diagnostics"
]

env.Replace(CFLAGS=pyrite_base_flags + ['-Icore'])
env.Replace(CXXFLAGS=pyrite_base_flags + [
    '-Icore',
    '-I' + os.path.join(TOOLCHAIN, 'include/c++/v1')
])

common_sources = [y for x in os.walk("Source") for y in Glob(os.path.join(x[0], '*.cpp'))]

env.StaticLibrary(
    target="libPyrite.a",
    source=common_sources    
)
