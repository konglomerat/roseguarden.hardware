# Edit following two lines to set component requirements (see docs)
set(COMPONENT_REQUIRES )
set(COMPONENT_PRIV_REQUIRES )

set(COMPONENT_SRCS 	"main.cpp"

					"drivers/Relay.cpp"
					"drivers/MOD_RFID1356.cpp"
					"drivers/Display.cpp"
					"drivers/Wifi.cpp"
					"drivers/Button.cpp"
					
					"graphics/Renderer.cpp"
					"graphics/implementation.cpp"
					"graphics/types/Frame.cpp"
					"graphics/types/Primitive.cpp"
					"graphics/types/Moveable.cpp"
					"graphics/primitives/TextBox.cpp"
					"graphics/primitives/generic/TextBoxBase.cpp"
					"graphics/text/FontManager.cpp"
					
					"network/JSONHttpClient.cpp"	
					"network/RoseguardenNodeClient.cpp"	
					
					"roseguarden/Door.cpp"			
					"roseguarden/Engine.cpp"
					"roseguarden/UI.cpp"
					"roseguarden/TextView.cpp"
					)
set(COMPONENT_ADD_INCLUDEDIRS ".")

register_component()

set_property(TARGET ${COMPONENT_TARGET} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${COMPONENT_TARGET} PROPERTY CXX_STANDARD_REQUIRED ON)

target_compile_options(${COMPONENT_LIB} PRIVATE -fconcepts)