#ifndef GRAPHICS_IMAGE_DATA_H_
#define GRAPHICS_IMAGE_DATA_H_

#include "../typedefs.h"

enum class ImageFormat {
    rgb888,
    rgba8888
};

class ImageData {
    ImageFormat format;
    uint width;
    uint height;
    void* data;
public:
    ImageData(ImageFormat format, uint width, uint height, void* data);
    ~ImageData();

    void* getData() const {
        return data;
    }

    ImageFormat getFormat() const {
        return format;
    }

    uint getWidth() const {
        return width;
    }

    uint getHeight() const {
        return height;
    }
};

extern ImageData* add_atlas_margins(ImageData* image, int grid_size);

#endif // GRAPHICS_IMAGE_DATA_H_