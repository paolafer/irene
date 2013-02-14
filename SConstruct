### ------------------------------------------------------------------
###  SConstruct - Building script for irene
###
###  Author : 
###  Created: 
###  Version: 
###
###  N.B. First time this script is executed, a configure-like step
###  tries to find out where are located the header and libraries
###  of irene dependencies (so far, only ROOT). If it succeeds, 
###  this configuration is stored in a file and used in following build 
### (until a clean is performed). The script tries to locate the 
###  dependencies by using
###  pkg-config scripts or searching at common paths. This should work
###  in most systems. However, if needed, users can provide via
###  command-line (or the BUILDVARS_FILE) the system path to any
###  dependency.
### ------------------------------------------------------------------

import os
import atexit

## File where the build variables are stored
BUILDVARS_FILE = 'buildvars.scons'

## Dummy default for path-like variables
DEFAULT_PATH = '.'

## pnext source code directories
SRCDIR = []


## Some useful functions

def filtered_glob(env, pattern, omit=[],
  ondisk=True, source=False, strings=False):
    return filter(
      lambda f: os.path.basename(f.path) not in omit,
      env.Glob(pattern))



def Abort(message):
    """Outputs a message before exiting the script with an error."""
    print 'scons: Build aborted.'
    print 'scons:', message
    Exit(1)

## Generates dictionaries for ROOT classes
def rootcint(target, source, env):
    """Executes the ROOT dictionary generator over a list of headers."""
    dictname = target[0]
    headers = ""
    for f in source:
        headers += str(f) + " " 

    command = "rootcint -f %s -c -p %s" %(dictname, headers)
    ok = os.system(command)
    return ok

## ###################################################################
## BUILD VARIABLES
## These variables can be used to specify (via command-line or file)
## the location of dependencies. They are also used to store in file
## configured values of compilation flags ($CPPPATH, $LIBS, etc.).

## Create a Variables instance associated to  a file
vars = Variables(BUILDVARS_FILE)

## Definition of the variables
vars.AddVariables(    
    
    ## ROOT

    PathVariable('ROOTSYS',
                 'Path to ROOT installation.',
                 DEFAULT_PATH),
    
    PathVariable('ROOT_INCDIR',
                 'Path to ROOT headers directory.',
                 DEFAULT_PATH),

    PathVariable('ROOT_LIBDIR',
                 'Path to ROOT libraries directory',
                 DEFAULT_PATH),

    
    ## The following vars shouldn't be defined by users unless they 
    ## know what they are doing.

    ('CPPDEFINES',
     'Preprocessor definitions.',
     []),
    
    ('CCFLAGS',
     'General options passed to the compiler.',
     []),

    ('CPPFLAGS',
     'User-specified preprocessor options.',
     []),
    
    ('CPPPATH',
     'List of directories where the include headers are located.',
     []),
    
    ('LIBPATH',
     'List of directories where the linked libraries are located.',
     []),
    
    ('LIBS',
     'List of libraries to link against.',
     []),
    
    ('LINKFLAGS',
     'User options passed to the linker.',
     [])

    )


## ###################################################################
## CONFIGURE BUILD

## Create a construction environment adding the build vars and
## propagating the user's external environment
env = Environment(variables=vars, ENV=os.environ)
env.AddMethod(filtered_glob, "FilteredGlob");

## If the LIBPATH buildvar is not defined, the configure step has
## not been run yet
if not env['LIBPATH']: 

    ## Create a Configure object that provides autoconf-like functionality
    conf = Configure(env, conf_dir='.sconf', log_file='.sconf/sconf.log')


    ## ROOT ..........................................................
        
    ROOTCONF = DEFAULT_PATH # full path to root-config

    if env['ROOTSYS'] != DEFAULT_PATH:
        ROOT_BINDIR = env['ROOTSYS'] + '/bin/'
    elif env['ENV']['ROOTSYS']:
        ROOT_BINDIR = env['ENV']['ROOTSYS'] + '/bin/'
    else:
        ROOT_BINDIR = ''

    try:
        env.ParseConfig(ROOT_BINDIR + 'root-config --cflags')
        env.ParseConfig(ROOT_BINDIR + 'root-config --libs')
    except OSError:
        Abort('ROOT headers and libraries could not be located.')
    
    
 
    env = conf.Finish()


# save build variables to file
vars.Save(BUILDVARS_FILE, env)

###################################################################### 
## BUILDING IRENE
######################################################################

env['CXXCOMSTR']  = "Compiling $SOURCE"
env['LINKCOMSTR'] = "Linking $TARGET"
env['CPPPATH'] += ['src']

headers = env.FilteredGlob('src/*.h', ['LinkDef.h'])

## Make a builder for ROOTCINT
bld = Builder(action = rootcint)
env.Append(BUILDERS = {'Rootcint' : bld}) 
env.Rootcint('ireneDict.cxx',headers+['src/LinkDef.h'])
#env.Rootcint('ireneDict.cxx', headers)

sourcefiles = Glob('src/*.cc')  
env.SharedLibrary('lib/irene', ['ireneDict.cxx']+sourcefiles)

## Install headers into include folder
#for item in headers:
#    print item

#if headers.index(Glob'src/LinkDef.h'):   
#if 'src/LinkDef.h' in headers:
#for item in headers:
#   print "here"
#   if item == 'src/LinkDef.h':
#      headers.remove(item)

#print "After deleting"
#for item in headers:
#    print item 

env.Install(headers)
#header_install = env.Install('include', headers)



