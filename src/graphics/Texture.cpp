#include "Texture.h"
#include <GL/glew.h>

Texture::Texture(unsigned int id, int width, int height) : id(id), width(width), height(height) {
}

Texture::Texture(unsigned char* data, int width, int height) : width(width), height(height) {
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	// glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, id);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid *) data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	// glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, 4, GL_RGBA, width, height, GL_TRUE);
	// glTexParameteri(GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	// glTexParameteri(GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);
	// glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, 0);
}

Texture::~Texture() {
	glDeleteTextures(1, &id);
}

void Texture::bind(){
	glBindTexture(GL_TEXTURE_2D, id);
	// glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, id);
}

void Texture::reload(unsigned char* data){
	glBindTexture(GL_TEXTURE_2D, id);
	// glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid *) data);
	// glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, 4, GL_RGB, width, height, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, 0);
	// glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, 0);
}
