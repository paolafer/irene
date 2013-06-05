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

## File where the library and include paths are stored
CONF_FILE = "irene.conf"

## Dummy default for path-like variables
DEFAULT_PATH = '.'

## pnext source code directories
SRCDIR = []

## write irene-config file
def write_config(dir_prefix):
    file = open("irene-config", 'w')
    s = '#! /bin/sh' + '\n' + '#irene-config'
    s = s + '\n' + '\n'
    s = s + 'prefix=' + dir_prefix + '\n'
    s = s + 'exec_prefix=${prefix}' + '\n'
    s = s + 'includedir=${prefix}/include'
    s = s + '\n' + '\n'
    s = s + 'usage()' + '\n' + '{' + '\n' + '    cat  <<EOF' + '\n'
    s = s + 'Usage: irene-config [OPTION]' + '\n' + '\n'
    s = s + 'Known values for OPTION are:' + '\n'
    s = s + '--prefix shw installation prefix' + '\n'
    s = s + '--include print include path' + '\n'
    s = s + '--ldflags print linker flags' + '\n'
    s = s + '--libs print name of libreries to link against' + '\n'
    s = s + '--help display this help and exit' + '\n'
    s = s + '--version print version information' + '\n' + '\n'
    s = s + 'EOF' + '\n' + '\n'
    s = s + '    exit $1' + '\n' + '}' + '\n' + '\n'
    s = s + 'if test $# -eq 0; then' + '\n' + '    usage 1' + '\n' + 'fi' + '\n'
    s = s + 'while test $# -gt 0; do' + '\n' + '    case "$1" in' + '\n' + '    -*=*)' + '\n'
    s = s + """        optarg=`echo "$1" | sed 's/[-_a-zA-Z0-9]*=//'`""" + '\n'  
    s = s +  '        ;;' + '\n' + '    *)' 
    s = s + '\n' + '        optarg=' + '\n' + '        ;;' + '    esac' + '\n' + '\n'
    s = s + '    case "$1" in' + '\n'
    s = s + '    --prefix)' + '\n' + '        echo ' + dir_prefix + '\n'
    s = s + '        ;;' + '\n' + '\n'
    s = s + '    --version)' + '\n' + '        echo ' + 'still to be implemented ' + '\n'
    s = s + '        exit 0' + '\n' + '        ;;' + '\n' + '\n'
    s = s +  '    --help)' + '\n' + '        usage 0' + '\n'
    s = s + '        ;;' + '\n' + '\n'
    s = s +  '    --include)' + '\n' + '        echo -I'+ dir_prefix + '/include' + '\n'
    s = s + '        ;;' + '\n' + '\n'
    s = s +  '    --ldflags)' + '\n' + '        echo -L'+ dir_prefix + '/lib' + '\n'
    s = s + '        ;;' + '\n' + '\n'
    s = s +  '    --libs)' + '\n' + '        echo -L'+ dir_prefix + '/lib' + ' -lirene' + '\n'
    s = s + '        ;;' + '\n' + '\n'
    s = s + '    *)' + '\n' + '        usage' +'\n' + '        exit 1' + '        ;;'
    s = s + '    esac' + '\n' + '    shift' + '\n' + 'done' + '\n' + '\n' + 'exit 0'
    file.write(s)
    env.ParseConfig('chmod 755 irene-config')

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
vars = Variables(CONF_FILE)

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

    PathVariable('PREFIX',
                 'Path to installation directory',
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

 #   ('PREFIX',
 #    'Path to installation directory',
 #    [DEFAULT_PATH])

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
vars.Save(CONF_FILE, env)

####### User-defined installation paths: #########
idir_prefix = '$PREFIX'
idir_lib    = '$PREFIX/lib'
idir_inc    = '$PREFIX/include/irene'
Export('env idir_prefix idir_lib idir_inc')

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

sourcefiles = Glob('src/*.cc')  

libirene = env.SharedLibrary(idir_lib + '/irene', ['ireneDict.cxx']+sourcefiles)

env.Install(idir_inc, headers)
env.Alias('install',idir_prefix)

w_prefix_dir = env['PREFIX']

## If the installation directory is the current one, find its absolute path
if env['PREFIX'] == DEFAULT_PATH:
   w_prefix_dir = os.getcwd()

write_config(w_prefix_dir)

## To remove all the file created during installation, when -c option is used
if GetOption("clean"):
  env.Default('install')

Clean(libirene, CONF_FILE)





