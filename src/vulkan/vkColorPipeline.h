/**
 * @file vkColorPipeline.h
 * @author Micah Pearlman (micahpearlman@gmail.com)
 * @brief A color pipeline using the color.vert and color.frag shaders
 * @version 0.1
 * @date 2024-10-18
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __VK_COLOR_PIPELINE_H__
#define __VK_COLOR_PIPELINE_H__

#include "vkGraphicsPipeline.h"

namespace MonkVG {
struct ColorPipeline_VertUBO {
    glm::mat4 u_model_view;
    glm::mat4 u_projection;
    glm::vec4 u_color;
};

struct ColorPipeline_FragUBO {
    // empty
};

class ColorPipeline : public VulkanGraphicsPipeline<ColorPipeline_VertUBO, ColorPipeline_FragUBO> {
  public:
    ColorPipeline(VulkanContext &context, VkPrimitiveTopology topology);
    ~ColorPipeline();

    void setColor(const glm::vec4 &color) { _vert_ubo_data.u_color = color; }
    void setColor(const color_t& color) {
        _vert_ubo_data.u_color = glm::vec4(color[0], color[1], color[2], color[3]);
    }
    const glm::vec4 &getColor() const { return _vert_ubo_data.u_color; }
};
} // namespace MonkVG
#endif // __VK_COLOR_PIPELINE_H__