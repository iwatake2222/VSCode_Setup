include makefile_config

TARGET = a.exe
SRCS = main.cpp ClassA.cpp
INCLUDES = -ISubModules
SUBS = SubModules/submodules.a
SUBDIRS = SubModules

all: sub_target $(TARGET)

$(TARGET): $(OBJS) $(SUBS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(SUBS) $(LIBS)

.PHONY: sub_target
sub_target:
ifdef SUBDIRS
	$(foreach subdir,$(SUBDIRS),cd $(subdir) && $(MAKE) && cd ../ &&) cd ./
endif

.PHONY: clean
clean:
	$(DEL) *.o *.a *.exe
ifdef SUBDIRS
	$(foreach subdir,$(SUBDIRS),cd $(subdir) && $(MAKE) clean && cd ../ &&) cd ./
endif

