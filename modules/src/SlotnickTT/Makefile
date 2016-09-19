#
# Temporary makefile system.
#

include buildsystem/Makedefaults

SOURCES := SlotnickTT.c \
           slotnick.c  \
           virieux.c

USE_SEP_LIB=YES
USE_FORTRAN=NO

# Enable debugging
ENABLE_DEBUG := NO

# Enable trace
ENABLE_TRACE := NO

# Disable src file/line number logging (enabled if debug is enabled)
DISABLE_SRC_LOG := YES

# Disable logging for type (INFO, WARN, etc)
DISABLE_TYPE_LOG := NO


# Any special includes go here as a list of dirs
INCLUDES := .

# List of all external libraries, in the form of -L<dir> -l<lib_name>
# This will be passed directly to the linker
#LIBS :=


# If different from build, specify it here
#BUILD_DIR :=

include $(BUILDSYSTEMDIR)/Makevars
