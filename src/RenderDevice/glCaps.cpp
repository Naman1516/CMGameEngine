#include<GL/glew.h>
#include<glfw3.h>
#include<hgl/LogInfo.h>
#include<string.h>
namespace hgl
{
	namespace graph
	{
		void PutOpenGLIntegerValue(const u16char *name,const GLenum flag)
		{
			int value;

			glGetIntegerv(flag,&value);

			if(glGetError()!=GL_INVALID_ENUM)
			{
				LOG_INFO(UTF16String(name)+u": "+UTF16String(value));
			}
			else
			{
				LOG_INFO(UTF16String(name)+u": nonsupport");
			}
		}

		void PutOpenGLFloatValue(const u16char *name,const GLenum flag)
		{
			float value;

			glGetFloatv(flag,&value);

			if(glGetError()!=GL_INVALID_ENUM)
			{
				LOG_INFO(UTF16String(name)+u": "+UTF16String(value));
			}
			else
			{
				LOG_INFO(UTF16String(name)+u": nonsupport");
			}
		}

		void PutOpenGLFloatRange(const u16char *name,const GLenum flag)
		{
			float value[2];

			glGetFloatv(flag,value);

			if(glGetError()!=GL_INVALID_ENUM)
			{
    			LOG_INFO(UTF16String(name)+u": "+UTF16String(value[0])+u" - "+UTF16String(value[1]));
			}
			else
			{
				LOG_INFO(UTF16String(name)+u": nonsupport");
			}
		}

		void PutOpenGLStringValue(const char *name,const GLenum flag)
		{
			char *str=(char *)glGetString(flag);

			if(glGetError()!=GL_INVALID_ENUM)
			{
				if(str)
				{
					LOG_INFO(UTF8String(name)+": "+UTF8String(str));
				}
				else
				{
					LOG_INFO(UTF8String(name)+": error");
				}
			}
			else
			{
				LOG_INFO(UTF8String(name)+": nonsupport");
			}
		}

		void PutOpenGLStringValue(const char *name,const char *str)
		{
			LOG_INFO(UTF8String(name)+": "+UTF8String(str));
		}

		void PutOpenGLFWVersion()
		{
			int major,minor,rev;

			glfwGetVersion(&major,&minor,&rev);

			LOG_INFO(OSString("GLFW Version: ")+OSString(major)+OS_TEXT(".")+OSString(minor)+OS_TEXT(".")+OSString(rev));
		}

		namespace OpenGLCore
		{
			void PutOpenGLInfo()
			{
				glGetError();

				LOG_INFO(OSString("OpenGL Info:"));

				PutOpenGLFWVersion();
				PutOpenGLStringValue(  "  GLEW Version",(char *)glewGetString(GLEW_VERSION));

				PutOpenGLStringValue(  "        Vendor",GL_VENDOR);
				PutOpenGLStringValue(  "      Renderer",GL_RENDERER);
				PutOpenGLStringValue(  "OpenGL Version",GL_VERSION);
				PutOpenGLStringValue(  "  GLSL Version",GL_SHADING_LANGUAGE_VERSION);

				int num;

				glGetIntegerv(GL_NUM_EXTENSIONS,&num);
				for(int i=0;i<num;i++)
				{
					LOG_INFO(UTF8String((char *)glGetStringi(GL_EXTENSIONS,i))+UTF8String(i?"":"Extensions: "));
				}

				PutOpenGLFloatRange	 (u"                        GL_POINT_SIZE_RANGE",GL_POINT_SIZE_RANGE);
				PutOpenGLFloatValue  (u"                  GL_POINT_SIZE_GRANULARITY",GL_POINT_SIZE_GRANULARITY);
				PutOpenGLFloatRange	 (u"                        GL_LINE_WIDTH_RANGE",GL_LINE_WIDTH_RANGE);
				PutOpenGLFloatValue  (u"                  GL_LINE_WIDTH_GRANULARITY",GL_LINE_WIDTH_GRANULARITY);
				PutOpenGLIntegerValue(u"                        GL_MAX_TEXTURE_SIZE",GL_MAX_TEXTURE_SIZE);
				PutOpenGLIntegerValue(u"               GL_MAX_CUBE_MAP_TEXTURE_SIZE",GL_MAX_CUBE_MAP_TEXTURE_SIZE);
				PutOpenGLIntegerValue(u"                   GL_MAX_RENDERBUFFER_SIZE",GL_MAX_RENDERBUFFER_SIZE);
				PutOpenGLIntegerValue(u"              GL_MAX_TEXTURE_MAX_ANISOTROPY",GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT);

				PutOpenGLIntegerValue(u"                        GL_MAX_DRAW_BUFFERS",GL_MAX_DRAW_BUFFERS);
				PutOpenGLIntegerValue(u"                      GL_MAX_VERTEX_ATTRIBS",GL_MAX_VERTEX_ATTRIBS);

				PutOpenGLIntegerValue(u"          GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS",GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS);		//最大vertex shader用贴图数量
				PutOpenGLIntegerValue(u"                 GL_MAX_TEXTURE_IMAGE_UNITS",GL_MAX_TEXTURE_IMAGE_UNITS);				//最大fragment shader用贴图数量
				PutOpenGLIntegerValue(u"        GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS",GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS);		//最大geometry shader用贴图数量
				PutOpenGLIntegerValue(u"        GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS",GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS);

				PutOpenGLIntegerValue(u"           GL_MAX_VERTEX_UNIFORM_COMPONENTS",GL_MAX_VERTEX_UNIFORM_COMPONENTS);
				PutOpenGLIntegerValue(u"         GL_MAX_FRAGMENT_UNIFORM_COMPONENTS",GL_MAX_FRAGMENT_UNIFORM_COMPONENTS);
				PutOpenGLIntegerValue(u"                      GL_MAX_VARYING_FLOATS",GL_MAX_VARYING_FLOATS);

				PutOpenGLIntegerValue(u"               GL_MAX_VERTEX_UNIFORM_BLOCKS",GL_MAX_VERTEX_UNIFORM_BLOCKS);
				PutOpenGLIntegerValue(u"             GL_MAX_GEOMETRY_UNIFORM_BLOCKS",GL_MAX_GEOMETRY_UNIFORM_BLOCKS);
				PutOpenGLIntegerValue(u"             GL_MAX_FRAGMENT_UNIFORM_BLOCKS",GL_MAX_FRAGMENT_UNIFORM_BLOCKS);
				PutOpenGLIntegerValue(u"             GL_MAX_COMBINED_UNIFORM_BLOCKS",GL_MAX_COMBINED_UNIFORM_BLOCKS);
				PutOpenGLIntegerValue(u"             GL_MAX_UNIFORM_BUFFER_BINDINGS",GL_MAX_UNIFORM_BUFFER_BINDINGS);
				PutOpenGLIntegerValue(u"                  GL_MAX_UNIFORM_BLOCK_SIZE",GL_MAX_UNIFORM_BLOCK_SIZE);
				PutOpenGLIntegerValue(u"  GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS",GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS);
				PutOpenGLIntegerValue(u"GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS",GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS);
				PutOpenGLIntegerValue(u"GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS",GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS);

				PutOpenGLIntegerValue(u"                 GL_MAX_TEXTURE_BUFFER_SIZE",GL_MAX_TEXTURE_BUFFER_SIZE);
			}
		}//namespace OpenGLCore
	}//namespace graph
}//namespace hgl
