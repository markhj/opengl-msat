# Custom shaders

You (fortunately) aren't obligated to use [shader builders](/getting-started/shader-builders).
If you want, you can create shader with custom source code.

````c++
const char* vertexShader = R"( ... )";
const char* fragmentShader = R"( ... )";

ShaderProgram shader;
shader.setSource(ShaderStage::Vertex, vertexShader);
shader.setSource(ShaderStage::Fragment, fragmentShader);
shader.compile();
````

See more about [shader stages](/lists/shader-stage).