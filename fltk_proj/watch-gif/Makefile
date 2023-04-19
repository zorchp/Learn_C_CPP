CXX      = $(shell fltk-config --cxx)
DEBUG    = -g
CXXFLAGS = $(shell fltk-config --use-gl --use-images --cxxflags ) -I.
LDFLAGS  = $(shell fltk-config --use-gl --use-images --ldflags )
LDSTATIC = $(shell fltk-config --use-gl --use-images --ldstaticflags )
LINK     = $(CXX)
 
TARGET = hello
OBJS =  main.o use-chinese.o
SRCS =  main.cpp use-chinese.cxx

APP_NAME= $(TARGET)

define info_plist
<?xml version="1.0" encoding="UTF-8"?> \
<plist version="0.9"> \
	<dict> \
	<key>CFBundleInfoDictionaryVersion</key> \
	<string>6.0</string> \
	<key>CFBundleExecutable</key> \
	<string>APP_NAME</string> \
	<key>CFBundleIdentifier</key> \
	<string>org.fltk.APP_NAME</string> \
	<key>CFBundleName</key> \
	<string>APP_NAME</string> \
	<key>CFBundlePackageType</key> \
	<string>APPL</string> \
	<key>NSHighResolutionCapable</key> \
	<true/> \
	</dict> \
</plist>
endef

.SUFFIXES: .o .cxx .cpp

all: compile link run

compile: $(SRCS)
	@echo "compiling..."
	@$(CXX) $(CXXFLAGS) $(DEBUG) -c $^

link: $(OBJS)
	@echo "linking..."
	@$(LINK) -o $(TARGET) $(OBJS) $(LDSTATIC)

run: compile link $(TARGET)
	./$(TARGET)

bundle_app: clean_app package_app

package_app: compile link
	@echo "bundling..."
	@mkdir -p $(APP_NAME).app/Contents/{MacOS,Resources}
	@echo '$(info_plist)' > "$(APP_NAME).app/Contents/Info.plist"
	@sed -e "s/APP_NAME/$(APP_NAME)/g" -i "" "$(APP_NAME).app/Contents/Info.plist"
	@cp $(TARGET) "$(APP_NAME).app/Contents/MacOS/$(APP_NAME)"
#	cp -R "$(FRAMEWORK_PATH)/SDL2.framework" "$(APP_NAME).app/Contents/Resources/"

clean: clean_app
	@echo "Delete *.o $(TARGET)..."
	@rm -f *.o 2> /dev/null
	@rm -f $(TARGET) 2> /dev/null

clean_app:
	@echo "Delete $(APP_NAME).app..."
	@rm -rf $(APP_NAME).app
