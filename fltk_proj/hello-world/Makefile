CXX      = $(shell fltk-config cxx)
DEBUG    = -g
CXXFLAGS = $(shell fltk-config --use-gl --use-images --cxxflags ) -I. -framework Cocoa
LDFLAGS  = $(shell fltk-config --use-gl --use-images --ldflags )
LDSTATIC = $(shell fltk-config --use-gl --use-images --ldstaticflags )
LINK     = $(CXX)

TARGET = test1
OBJS =  test1.o
SRCS =  test1.cpp
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
%.o: %.cxx
	$(CXX) $(CXXFLAGS) $(DEBUG) -c $<

$(TARGET): $(OBJS)
	$(LINK) -o $(TARGET) $(OBJS) $(LDSTATIC)

test1.o: test1.cpp
all: $(TARGET) clean_app package_app

run: $(TARGET)
	./$(TARGET)

package_app:
	mkdir -p $(APP_NAME).app/Contents/{MacOS,Resources}
	export info_plist
	echo '$(info_plist)' > "$(APP_NAME).app/Contents/Info.plist"
	sed -e "s/APP_NAME/$(APP_NAME)/g" -i "" "$(APP_NAME).app/Contents/Info.plist"
	cp $(TARGET) "$(APP_NAME).app/Contents/MacOS/$(APP_NAME)"
#	cp -R "$(FRAMEWORK_PATH)/SDL2.framework" "$(APP_NAME).app/Contents/Resources/"


clean: clean_app
	rm -f *.o 2> /dev/null
	rm -f $(TARGET) 2> /dev/null

clean_app:
	rm -rf $(APP_NAME).app
