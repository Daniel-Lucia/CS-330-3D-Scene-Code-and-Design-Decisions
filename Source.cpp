/*
* Daniel Lucia
* 08 / 13 / 2023
* Module Seven 7-1 Project
*/
#pragma once
#include <iostream> // cout, cerr
#include <cstdlib> // EXIT_FAILURE
#include <GL/glew.h> // GLEW library
#include <GLFW/glfw3.h> // GLFW library
#include <camera.h> //camera library
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h" // Image loading utility functions
// GLM Math Header inclusions
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace std; // Standard namespace
/*Shader program Macro*/
#ifndef GLSL
#define GLSL(Version, Source) "#version " #Version " core \n" #Source
#endif
// Unnamed namespace
namespace
{
	const char* const WINDOW_TITLE = "Module Seven Project"; // Macro for window title
	// Variables for window width and height
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	// Stores the GL data relative to a given mesh
	struct GLMesh
	{
		// Handle for plane
		GLuint planeVao;
		GLuint planeVbo;
		GLuint nPlaneVertices;
		// Handle for pot holder
		GLuint potHolderVao;
		GLuint potHolderVbo;
		GLuint nPotHolderVertices;
		// Handle for spatula
		GLuint spatulaVao;
		GLuint spatulaVbo;
		GLuint nSpatulaVertices;
		// Handle for spatula Head
		GLuint spatulaHeadVao;
		GLuint spatulaHeadVbo;
		GLuint nSpatulaHeadVertices;
		// Handle for second spatula
		GLuint spatulaTwoVao;
		GLuint spatulaTwoVbo;
		GLuint nSpatulaTwoVertices;
		// Handle for second spatula Head
		GLuint spatulaTwoHeadVao;
		GLuint spatulaTwoHeadVbo;
		GLuint nSpatulaTwoHeadVertices;
		// Handle for bottle
		GLuint bottleVao;
		GLuint bottleVbos;
		GLuint nBottleVertices;
		// Handle for bottle neck
		GLuint bottleNeckVao;
		GLuint bottleNeckVbo;
		GLuint nBottleNeckVertices;
		// Handle for seasoning
		GLuint seasoningVao;
		GLuint seasoningVbo;
		GLuint nSeasoningVertices;
		// Handle for seasoning neck
		GLuint seasoningNeckVao;
		GLuint seasoningNeckVbo;
		GLuint nSeasoningNeckVertices;
		// Handle for seasoning
		GLuint seasoningTopVao;
		GLuint seasoningTopVbo;
		GLuint nSeasoningTopVertices;
		// Handle for second seasoning
		GLuint seasoningTwoVao;
		GLuint seasoningTwoVbo;
		GLuint nSeasoningTwoVertices;
		// Handle for seasoning neck
		GLuint seasoningTwoNeckVao;
		GLuint seasoningTwoNeckVbo;
		GLuint nSeasoningTwoNeckVertices;
		// Handle for seasoning
		GLuint seasoningTwoTopVao;
		GLuint seasoningTwoTopVbo;
		GLuint nSeasoningTwoTopVertices;
		// Lamp
		GLuint vao[3]; // Handle for the vertex array object
		GLuint vbo[3]; // Handle for the vertex buffer object
		GLuint nVertices[3]; // Number of indices of the mesh
	};
	// Main GLFW window
	GLFWwindow* gWindow = nullptr;
	// Triangle mesh data
	GLMesh gMesh;
	// Shader program
	GLuint gProgramId;
	GLuint gCubeProgramId;
	GLuint gLampProgramId;
	// Texture Ids
	GLuint gPlaneTexture;
	GLuint gPotHolderTexture;
	GLuint gSpatulaTexture;
	GLuint gSpatulaHeadTexture;
	GLuint gSpatulaTwoTexture;
	GLuint gSpatulaTwoHeadTexture;
	GLuint gBottleTexture;
	GLuint gBottleNeckTexture;
	GLuint gSeasoningTexture;
	GLuint gSeasoningNeckTexture;
	GLuint gSeasoningTopTexture;
	GLuint gSeasoningTwoTexture;
	GLuint gSeasoningTwoNeckTexture;
	GLuint gSeasoningTwoTopTexture;
	glm::vec2 gUVScale(1.0f, 1.0f);
	GLint gTexWrapMode = GL_REPEAT;
	// camera
	Camera gCamera(glm::vec3(0.0f, 0.0f, 3.0f));
	float gLastX = WINDOW_WIDTH / 2.0f;
	float gLastY = WINDOW_HEIGHT / 2.0f;
	bool gFirstMouse = true;
	bool ortho = false;
	// timing
	float gDeltaTime = 0.0f; // time between current frame and last frame
	float gLastFrame = 0.0f;
	// Subject position and scale
	glm::vec3 gCubePosition(0.0f, 0.0f, 0.0f);
	glm::vec3 gCubeScale(2.0f);
	// Cube and light color
	//m::vec3 gObjectColor(0.6f, 0.5f, 0.75f);
	glm::vec3 gObjectColor(1.0f, 1.0f, 1.0f);
	glm::vec3 gLightColor(1.0f, 1.0f, 1.0f);
	// Light position and scale
	glm::vec3 gLightPosition(0.0f, 4.0f, 0.0f);
	glm::vec3 gLightScale(0.3f);
}
/* User-defined Function prototypes to:
 * initialize the program, set the window size,
 * redraw graphics on the window when resized,
 * and render graphics on the screen
 */
bool UInitialize(int, char* [], GLFWwindow** window);
void UResizeWindow(GLFWwindow* window, int width, int height);
void UProcessInput(GLFWwindow* window);
void UMousePositionCallback(GLFWwindow* window, double xpos, double ypos);
void UMouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
void UMouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void UCreateTexturedMesh(GLMesh& mesh);
void UDestroyMesh(GLMesh& mesh);
bool UCreateTexture(const char* filename, GLuint& textureId);
void UDestroyTexture(GLuint textureId);
void URender();
bool UCreateShaderProgram(const char* vtxShaderSource, const char* fragShaderSource, GLuint& programId);
void UDestroyShaderProgram(GLuint programId);
/* Vertex Shader Source Code*/
const GLchar* vertexShaderSource = GLSL(440,
	layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 textureCoordinate;
out vec3 vertexNormal;
out vec3 vertexFragmentPos;
out vec2 vertexTextureCoordinate;
//Global variables for the transform matrices
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
void main()
{
	gl_Position = projection * view * model * vec4(position, 1.0f); // transforms vertices to clip coordinates
	vertexFragmentPos = vec3(model * vec4(position, 1.0f)); // Gets fragment / pixel position in world space only
	vertexNormal = mat3(transpose(inverse(model))) * normal; // get normal	vectors in world space
	vertexTextureCoordinate = textureCoordinate;
}
);
/* Fragment Shader Source Code*/
const GLchar* fragmentShaderSource = GLSL(440,
	in vec3 vertexNormal; // Incoming noramls
in vec3 vertexFragmentPos; // Incoming fragment position
in vec2 vertexTextureCoordinate; // Incoming texture coordinates
out vec4 fragmentColor;
uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 caseColor;
uniform vec3 lightPos;
uniform vec3 viewPosition;
uniform sampler2D uTexture; // Useful when working with multiple textures
uniform vec2 uvScale;
void main()
{
	/*Phong lighting model calculations to generate ambient, diffuse, and
	specular components*/
	//Calculate Ambient lighting*/
	float ambientStrength = 0.5f; // Set ambient or global lighting strength
	vec3 ambient = ambientStrength * lightColor; // Generate ambient light color
	//Calculate Diffuse lighting*/
	vec3 norm = normalize(vertexNormal); // Normalize vectors to 1 unit
	vec3 lightDirection = normalize(lightPos - vertexFragmentPos); // Calculate distance(light direction) between light source and fragments / pixels on cube
	float impact = max(dot(norm, lightDirection), 0.0);// Calculate diffuse impact by generating dot product of normal and light
	vec3 diffuse = impact * lightColor; // Generate diffuse light color
	//Calculate Specular lighting*/
	float specularIntensity = 0.8f; // Set specular light strength
	float highlightSize = 12.0f; // Set specular highlight size
	vec3 viewDir = normalize(viewPosition - vertexFragmentPos); // Calculate view direction
	vec3 reflectDir = reflect(-lightDirection, norm);// Calculate reflection vector
	//Calculate specular component
	float specularComponent = pow(max(dot(viewDir, reflectDir), 0.0), highlightSize);
	vec3 specular = specularIntensity * specularComponent * lightColor;
	// Texture holds the color to be used for all three components
	vec4 textureColor = texture(uTexture, vertexTextureCoordinate * uvScale);
	// Calculate phong result
	vec3 phong = (ambient + diffuse + specular) * textureColor.xyz;
	fragmentColor = vec4(phong, 1.0); // Send lighting results to GPU
}
);

/* Lamp Shader Source Code*/
const GLchar* lampVertexShaderSource = GLSL(440,
	layout(location = 0) in vec3 position; // VAP position 0 for vertex position data
//Uniform / Global variables for the transform matrices
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
void main()
{
	gl_Position = projection * view * model * vec4(position, 1.0f); // Transforms vertices into clip coordinates
}
);
/* Fragment Shader Source Code*/
const GLchar* lampFragmentShaderSource = GLSL(440,
	out vec4 fragmentColor; // For outgoing lamp color (smaller cube) to the GPU
void main()
{
	fragmentColor = vec4(1.0f); // Set color to white (1.0f,1.0f,1.0f) with alpha 1.0
}
);
// Images are loaded with Y axis going down, but OpenGL's Y axis goes up, so let's flip it
void flipImageVertically(unsigned char* image, int width, int height, int channels)
{
	for (int j = 0; j < height / 2; ++j)
	{
		int index1 = j * width * channels;
		int index2 = (height - 1 - j) * width * channels;
		for (int i = width * channels; i > 0; --i)
		{
			unsigned char tmp = image[index1];
			image[index1] = image[index2];
			image[index2] = tmp;
			++index1;
			++index2;
		}
	}
}
int main(int argc, char* argv[])
{
	if (!UInitialize(argc, argv, &gWindow))
		return EXIT_FAILURE;
	// Create the mesh
	UCreateTexturedMesh(gMesh); // Calls the function to create the Vertex Buffer Object
	// Create the shader program
	if (!UCreateShaderProgram(vertexShaderSource, fragmentShaderSource, gProgramId))
		return EXIT_FAILURE;

	if (!UCreateShaderProgram(lampVertexShaderSource, lampFragmentShaderSource, gLampProgramId))
		return EXIT_FAILURE;
	//Load textures
	const char* texFileName = "countertop.jpg";
	if (!UCreateTexture(texFileName, gPlaneTexture)) {
		cout << "Failed to load texture " << texFileName << endl;
		return EXIT_FAILURE;
	}
	texFileName = "potholder.jpg";
	if (!UCreateTexture(texFileName, gPotHolderTexture)) {
		cout << "Failed to load texture " << texFileName << endl;
		return EXIT_FAILURE;
	}
	texFileName = "spatula.jpg";
	if (!UCreateTexture(texFileName, gSpatulaTexture)) {
		cout << "Failed to load texture " << texFileName << endl;
		return EXIT_FAILURE;
	}
	texFileName = "spatula.jpg";
	if (!UCreateTexture(texFileName, gSpatulaHeadTexture)) {
		cout << "Failed to load texture " << texFileName << endl;
		return EXIT_FAILURE;
	}
	texFileName = "spatula.jpg";
	if (!UCreateTexture(texFileName, gSpatulaTwoTexture)) {
		cout << "Failed to load texture " << texFileName << endl;
		return EXIT_FAILURE;
	}
	texFileName = "spatula.jpg";
	if (!UCreateTexture(texFileName, gSpatulaTwoHeadTexture)) {
		cout << "Failed to load texture " << texFileName << endl;
		return EXIT_FAILURE;
	}
	texFileName = "bottle.jpg";
	if (!UCreateTexture(texFileName, gBottleTexture)) {
		cout << "Failed to load texture " << texFileName << endl;
		return EXIT_FAILURE;
	}
	texFileName = "bottle.jpg";
	if (!UCreateTexture(texFileName, gBottleNeckTexture)) {
		cout << "Failed to load texture " << texFileName << endl;
		return EXIT_FAILURE;
	}
	texFileName = "seasoning.jpg";
	if (!UCreateTexture(texFileName, gSeasoningTexture)) {
		cout << "Failed to load texture " << texFileName << endl;
		return EXIT_FAILURE;
	}
	texFileName = "seasoning.jpg";
	if (!UCreateTexture(texFileName, gSeasoningNeckTexture)) {
		cout << "Failed to load texture " << texFileName << endl;
		return EXIT_FAILURE;
	}
	texFileName = "spatula.jpg";
	if (!UCreateTexture(texFileName, gSeasoningTopTexture)) {
		cout << "Failed to load texture " << texFileName << endl;
		return EXIT_FAILURE;
	}
	texFileName = "seasoning.jpg";
	if (!UCreateTexture(texFileName, gSeasoningTwoTexture)) {
		cout << "Failed to load texture " << texFileName << endl;
		return EXIT_FAILURE;
	}
	texFileName = "seasoning.jpg";
	if (!UCreateTexture(texFileName, gSeasoningTwoNeckTexture)) {
		cout << "Failed to load texture " << texFileName << endl;
		return EXIT_FAILURE;
	}
	texFileName = "spatula.jpg";
	if (!UCreateTexture(texFileName, gSeasoningTwoTopTexture)) {
		cout << "Failed to load texture " << texFileName << endl;
		return EXIT_FAILURE;
	}
	glUseProgram(gProgramId);
	// Set texture units
	glUniform1i(glGetUniformLocation(gProgramId, "uTexturePlane"), 0);
	glUniform1i(glGetUniformLocation(gProgramId, "uTexturePotHolder"), 1);
	glUniform1i(glGetUniformLocation(gProgramId, "uTextureSpatula"), 2);
	glUniform1i(glGetUniformLocation(gProgramId, "uTextureSpatulaHead"), 3);
	glUniform1i(glGetUniformLocation(gProgramId, "uTextureSpatulaTwo"), 4);
	glUniform1i(glGetUniformLocation(gProgramId, "uTextureSpatulaTwoHead"), 5);
	glUniform1i(glGetUniformLocation(gProgramId, "uTextureBottle"), 6);
	glUniform1i(glGetUniformLocation(gProgramId, "uTextureBottleNeck"), 7);
	glUniform1i(glGetUniformLocation(gProgramId, "uTextureSeasoning"), 8);
	glUniform1i(glGetUniformLocation(gProgramId, "uTextureSeasoningNeck"), 9);
	glUniform1i(glGetUniformLocation(gProgramId, "uTextureSeasoningTop"), 10);
	glUniform1i(glGetUniformLocation(gProgramId, "uTextureSeasoningTwo"), 11);
	glUniform1i(glGetUniformLocation(gProgramId, "uTextureSeasoningTwoNeck"), 12);
	glUniform1i(glGetUniformLocation(gProgramId, "uTextureSeasoningTwoTop"), 13);
	// Sets the background color of the window to black (it will be implicitely used by glClear)
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	// render loop
	while (!glfwWindowShouldClose(gWindow))
	{
		// per-frame timing
		float currentFrame = glfwGetTime();
		gDeltaTime = currentFrame - gLastFrame;
		gLastFrame = currentFrame;
		// input
		UProcessInput(gWindow);
		// Render this frame
		URender();
		glfwPollEvents();
	}
	// Release mesh data
	UDestroyMesh(gMesh);
	// Release texture
	UDestroyTexture(gPlaneTexture);
	UDestroyTexture(gPotHolderTexture);
	UDestroyTexture(gSpatulaTexture);
	UDestroyTexture(gSpatulaHeadTexture);
	UDestroyTexture(gSpatulaTwoTexture);
	UDestroyTexture(gSpatulaTwoHeadTexture);
	UDestroyTexture(gBottleTexture);
	UDestroyTexture(gBottleNeckTexture);
	UDestroyTexture(gSeasoningTexture);
	UDestroyTexture(gSeasoningNeckTexture);
	UDestroyTexture(gSeasoningTopTexture);
	UDestroyTexture(gSeasoningTwoTexture);
	UDestroyTexture(gSeasoningTwoNeckTexture);
	UDestroyTexture(gSeasoningTwoTopTexture);
	// Release shader program
	UDestroyShaderProgram(gProgramId);
	exit(EXIT_SUCCESS); // Terminates the program successfully
}
// Initialize GLFW, GLEW, and create a window
bool UInitialize(int argc, char* argv[], GLFWwindow** window)
{
	// GLFW: initialize and configure
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	// GLFW: window creation
	* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL,
		NULL);
	// If window creatin fails, terminate
	if (*window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(*window);
	glfwSetFramebufferSizeCallback(*window, UResizeWindow);
	glfwSetCursorPosCallback(*window, UMousePositionCallback);
	glfwSetScrollCallback(*window, UMouseScrollCallback);
	glfwSetMouseButtonCallback(*window, UMouseButtonCallback);
	// tell GLFW to capture our mouse
	glfwSetInputMode(*window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	// GLEW: initialize
	glewExperimental = GL_TRUE;
	GLenum GlewInitResult = glewInit();
	if (GLEW_OK != GlewInitResult)
	{
		std::cerr << glewGetErrorString(GlewInitResult) << std::endl;
		return false;
	}
	// Displays GPU OpenGL version
	cout << "INFO: OpenGL Version: " << glGetString(GL_VERSION) << endl;
	return true;
}
// Process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void UProcessInput(GLFWwindow* window)
{
	static const float cameraSpeed = 2.5f;
	// Terminates program if escape pressed
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	// Moves left, right, forward, and backward
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		gCamera.ProcessKeyboard(FORWARD, gDeltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		gCamera.ProcessKeyboard(BACKWARD, gDeltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		gCamera.ProcessKeyboard(LEFT, gDeltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		gCamera.ProcessKeyboard(RIGHT, gDeltaTime);
	// Moves camera up and down
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
		gCamera.ProcessKeyboard(UP, gDeltaTime);
	}
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
		gCamera.ProcessKeyboard(DOWN, gDeltaTime);
	}
	// Changes orthographic/perspective camera view
	if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS) {
		ortho = true;
	}
	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) {
		ortho = false;
	}
	//reset camera to default speed and setting
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		gCamera = glm::vec3(0.0f, 0.0f, 3.0f);
		//cameraSpeed = 2.5f;
	}
	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS && gTexWrapMode != GL_REPEAT)
	{
		glBindTexture(GL_TEXTURE_2D, gPlaneTexture);
		glBindTexture(GL_TEXTURE_2D, gPotHolderTexture);
		glBindTexture(GL_TEXTURE_2D, gSpatulaTexture);
		glBindTexture(GL_TEXTURE_2D, gSpatulaHeadTexture);
		glBindTexture(GL_TEXTURE_2D, gSpatulaTwoTexture);
		glBindTexture(GL_TEXTURE_2D, gSpatulaTwoHeadTexture);
		glBindTexture(GL_TEXTURE_2D, gBottleNeckTexture);
		glBindTexture(GL_TEXTURE_2D, gBottleTexture);
		glBindTexture(GL_TEXTURE_2D, gSeasoningTexture);
		glBindTexture(GL_TEXTURE_2D, gSeasoningNeckTexture);
		glBindTexture(GL_TEXTURE_2D, gSeasoningTopTexture);
		glBindTexture(GL_TEXTURE_2D, gSeasoningTwoTexture);
		glBindTexture(GL_TEXTURE_2D, gSeasoningTwoNeckTexture);
		glBindTexture(GL_TEXTURE_2D, gSeasoningTwoTopTexture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBindTexture(GL_TEXTURE_2D, 0);
		gTexWrapMode = GL_REPEAT;
		cout << "Current texture wrapping mode: REPEAT" << endl;
	}
	else if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS && gTexWrapMode !=
		GL_MIRRORED_REPEAT) {
		glBindTexture(GL_TEXTURE_2D, gPlaneTexture);
		glBindTexture(GL_TEXTURE_2D, gPotHolderTexture);
		glBindTexture(GL_TEXTURE_2D, gSpatulaTexture);
		glBindTexture(GL_TEXTURE_2D, gSpatulaHeadTexture);
		glBindTexture(GL_TEXTURE_2D, gSpatulaTwoTexture);
		glBindTexture(GL_TEXTURE_2D, gSpatulaTwoHeadTexture);
		glBindTexture(GL_TEXTURE_2D, gBottleNeckTexture);
		glBindTexture(GL_TEXTURE_2D, gBottleTexture);
		glBindTexture(GL_TEXTURE_2D, gSeasoningTexture);
		glBindTexture(GL_TEXTURE_2D, gSeasoningNeckTexture);
		glBindTexture(GL_TEXTURE_2D, gSeasoningTopTexture);
		glBindTexture(GL_TEXTURE_2D, gSeasoningTwoTexture);
		glBindTexture(GL_TEXTURE_2D, gSeasoningTwoNeckTexture);
		glBindTexture(GL_TEXTURE_2D, gSeasoningTwoTopTexture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
		glBindTexture(GL_TEXTURE_2D, 0);
		gTexWrapMode = GL_MIRRORED_REPEAT;
		cout << "Current Texture Wrapping Mode: MIRRORED REPEAT" << endl;
	}
	else if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS && gTexWrapMode !=
		GL_CLAMP_TO_EDGE) {
		glBindTexture(GL_TEXTURE_2D, gPlaneTexture);
		glBindTexture(GL_TEXTURE_2D, gPotHolderTexture);
		glBindTexture(GL_TEXTURE_2D, gSpatulaTexture);
		glBindTexture(GL_TEXTURE_2D, gSpatulaHeadTexture);
		glBindTexture(GL_TEXTURE_2D, gSpatulaTwoTexture);
		glBindTexture(GL_TEXTURE_2D, gSpatulaTwoHeadTexture);
		glBindTexture(GL_TEXTURE_2D, gBottleNeckTexture);
		glBindTexture(GL_TEXTURE_2D, gBottleTexture);
		glBindTexture(GL_TEXTURE_2D, gSeasoningTexture);
		glBindTexture(GL_TEXTURE_2D, gSeasoningNeckTexture);
		glBindTexture(GL_TEXTURE_2D, gSeasoningTopTexture);
		glBindTexture(GL_TEXTURE_2D, gSeasoningTwoTexture);
		glBindTexture(GL_TEXTURE_2D, gSeasoningTwoNeckTexture);
		glBindTexture(GL_TEXTURE_2D, gSeasoningTwoTopTexture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glBindTexture(GL_TEXTURE_2D, 0);
		gTexWrapMode = GL_CLAMP_TO_EDGE;
		cout << "Current Texture Wrapping Mode: CLAMP TO EDGE" << endl;
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT_BRACKET) == GLFW_PRESS)
	{
		gUVScale += 0.1f;
		cout << "Current scale (" << gUVScale[0] << ", " << gUVScale[1] << ")" << endl;
	}
	else if (glfwGetKey(window, GLFW_KEY_LEFT_BRACKET) == GLFW_PRESS)
	{
		gUVScale -= 0.1f;
		cout << "Current scale (" << gUVScale[0] << ", " << gUVScale[1] << ")" << endl;
	}
}
// GLFW: Whenever the window size changed (by OS or user resize) this callback function executes
void UResizeWindow(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
// GLFW: whenever the mouse moves, this callback is called
void UMousePositionCallback(GLFWwindow* window, double xpos, double ypos)
{
	if (gFirstMouse)
	{
		gLastX = xpos;
		gLastY = ypos;
		gFirstMouse = false;
	}
	float xoffset = xpos - gLastX;
	float yoffset = gLastY - ypos; // reversed since y-coordinates go from bottom to top
	gLastX = xpos;
	gLastY = ypos;
	gCamera.ProcessMouseMovement(xoffset, yoffset);
}
// GLFW: whenever the mouse scroll wheel scrolls, this callback is called
void UMouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	gCamera.ProcessMouseScroll(yoffset);
}
// GLFW: handle mouse button events
void UMouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	switch (button)
	{
		// Left mouse button clicked
	case GLFW_MOUSE_BUTTON_LEFT:
	{
		if (action == GLFW_PRESS)
			cout << "Left mouse button pressed" << endl;
		else
			cout << "Left mouse button released" << endl;
	}
	break;
	// Middle mouse button clicked
	case GLFW_MOUSE_BUTTON_MIDDLE:
	{
		if (action == GLFW_PRESS)
			cout << "Middle mouse button pressed" << endl;
		else
			cout << "Middle mouse button released" << endl;
	}
	break;
	// Right mouse button clicked
	case GLFW_MOUSE_BUTTON_RIGHT:
	{
		if (action == GLFW_PRESS)
			cout << "Right mouse button pressed" << endl;
		else
			cout << "Right mouse button released" << endl;
	}
	break;
	// Unknown mouse button clicked
	default:
		cout << "Unhandled mouse button event" << endl;
		break;
	}
}
// Function called to render a frame
void URender()
{
	// Enable z-depth
	glEnable(GL_DEPTH_TEST);
	// Clear the frame and z buffers
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Set the shader to be used
	glUseProgram(gProgramId);
	// Scale, rotate, and translate object
	glm::mat4 scale = glm::scale(glm::vec3(1.0f, 1.0f, 1.0f));
	glm::mat4 rotation = glm::rotate(0.0f, glm::vec3(1.0, 1.0f, 1.0f));
	glm::mat4 translation = glm::translate(glm::vec3(0.0f, 4.0f, 0.0f));
	// Model matrix: transformations are applied right-to-left order
	glm::mat4 model = translation * rotation * scale;
	// camera/view transformation
	glm::mat4 view = gCamera.GetViewMatrix();
	// Creates a perspective projection
	glm::mat4 projection = glm::ortho(-10.0f, 10.0f, -10.0f, 100.0f, -100.0f, 100.0f);
	if (!ortho) {
		projection = glm::perspective(glm::radians(gCamera.Zoom),
			(GLfloat)WINDOW_WIDTH / (GLfloat)WINDOW_HEIGHT, 0.1f, 100.0f);
	}
	if (ortho) {
		projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -10.0f, 10.0f);
	};
	/*glm::mat4 transformation(1.0f);*/
	// Retrieves and passes transform matrices to the Shader program
	GLint modelLoc = glGetUniformLocation(gProgramId, "model");
	GLint viewLoc = glGetUniformLocation(gProgramId, "view");
	GLint projLoc = glGetUniformLocation(gProgramId, "projection");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
	// Reference matrix uniforms from the Cube Shader program for the cub color, light color, light position, and camera position
	GLint objectColorLoc = glGetUniformLocation(gProgramId, "objectColor");
	GLint lightColorLoc = glGetUniformLocation(gProgramId, "lightColor");
	GLint lightPositionLoc = glGetUniformLocation(gProgramId, "lightPos");
	GLint viewPositionLoc = glGetUniformLocation(gProgramId, "viewPosition");
	// Pass color, light, and camera data to the Cube Shader program's corresponding uniforms
	glUniform3f(objectColorLoc, gObjectColor.r, gObjectColor.g, gObjectColor.b);
	glUniform3f(lightColorLoc, gLightColor.r, gLightColor.g, gLightColor.b);
	glUniform3f(lightPositionLoc, gLightPosition.x, gLightPosition.y, gLightPosition.z);
	const glm::vec3 cameraPosition = gCamera.Position;
	glUniform3f(viewPositionLoc, cameraPosition.x, cameraPosition.y, cameraPosition.z);
	GLuint UVScaleLoc = glGetUniformLocation(gProgramId, "uvScale");
	glUniform2fv(UVScaleLoc, 1, glm::value_ptr(gUVScale));

	// Sends transform information to the Vertex shader
	//GLuint transformLocation = glGetUniformLocation(gProgramId, "shaderTransform");
	//glUniformMatrix4fv(transformLocation, 1, GL_FALSE, glm::value_ptr(transformation));

	// Plane
	glBindVertexArray(gMesh.planeVao);
	model = glm::mat4(1.0f);
	// Bind textures
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, gPlaneTexture);
	// Draw Plane
	glDrawArrays(GL_TRIANGLES, 0, gMesh.nPlaneVertices);
	//////////////////////////////////
	// Pot Holder
	// Scale, rotate, and translate bottle
	glm::mat4 potHolderScale = glm::scale(glm::vec3(1.0f, 2.0f, 1.0f));
	glm::mat4 potHolderRotation = glm::rotate(0.0f, glm::vec3(0.0, 1.0f, 0.0f));
	glm::mat4 potHolderTranslation = glm::translate(glm::vec3(-1.1f, 2.1f, -1.0f));
	// Model matrix: transformations are applied right-to-left order
	glm::mat4 potHolderModel = potHolderTranslation * potHolderRotation * potHolderScale;
	// Retrieves and passes transform matrices to the Shader program
	GLint potHolderModelLoc = glGetUniformLocation(gProgramId, "model");
	GLint potHolderViewLoc = glGetUniformLocation(gProgramId, "view");
	GLint potHolderProjLoc = glGetUniformLocation(gProgramId, "projection");
	glUniformMatrix4fv(potHolderModelLoc, 1, GL_FALSE, glm::value_ptr(potHolderModel));
	glUniformMatrix4fv(potHolderViewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(potHolderProjLoc, 1, GL_FALSE, glm::value_ptr(projection));
	// Draws pot holders
	glBindVertexArray(gMesh.potHolderVao);
	model = glm::mat4(1.0f);
	// Bind textures
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, gPotHolderTexture);
	// Draw pot holders
	glDrawArrays(GL_TRIANGLES, 0, gMesh.nPotHolderVertices);
	//////////////////////////////////
	// Spatula
	// Scale, rotate, and translate bottle
	glm::mat4 spatulaScale = glm::scale(glm::vec3(1.0f, 2.0f, 1.0f));
	glm::mat4 spatulaRotation = glm::rotate(-4.7f, glm::vec3(0.0, 1.0f, 0.0f));
	glm::mat4 spatulaTranslation = glm::translate(glm::vec3(-1.7f, -0.7f, 1.0f));
	// Model matrix: transformations are applied right-to-left order
	glm::mat4 spatulaModel = spatulaTranslation * spatulaRotation * spatulaScale;
	// Retrieves and passes transform matrices to the Shader program
	GLint spatulaModelLoc = glGetUniformLocation(gProgramId, "model");
	GLint spatulaViewLoc = glGetUniformLocation(gProgramId, "view");
	GLint spatulaProjLoc = glGetUniformLocation(gProgramId, "projection");
	glUniformMatrix4fv(spatulaModelLoc, 1, GL_FALSE, glm::value_ptr(spatulaModel));
	glUniformMatrix4fv(spatulaViewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(spatulaProjLoc, 1, GL_FALSE, glm::value_ptr(projection));
	// Draws Spatula
	glBindVertexArray(gMesh.spatulaVao);
	model = glm::mat4(1.0f);
	// Bind textures
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, gSpatulaTexture);
	// Draw Spatula
	glDrawArrays(GL_TRIANGLES, 0, gMesh.nSpatulaVertices);
	//////////////////////////////////
	// Spatula Head
	// Scale, rotate, and translate bottle
	glm::mat4 spatulaHeadScale = glm::scale(glm::vec3(1.0f, 0.2f, 1.0f));
	glm::mat4 spatulaHeadRotation = glm::rotate(-4.7f, glm::vec3(0.05, 1.0f, 0.06f));
	glm::mat4 spatulaHeadTranslation = glm::translate(glm::vec3(-1.73f, -0.67f, -0.9f));
	// Model matrix: transformations are applied right-to-left order
	glm::mat4 spatulaHeadModel = spatulaHeadTranslation * spatulaHeadRotation * spatulaHeadScale;
	// Retrieves and passes transform matrices to the Shader program
	GLint spatulaHeadModelLoc = glGetUniformLocation(gProgramId, "model");
	GLint spatulaHeadViewLoc = glGetUniformLocation(gProgramId, "view");
	GLint spatulaHeadProjLoc = glGetUniformLocation(gProgramId, "projection");
	glUniformMatrix4fv(spatulaModelLoc, 1, GL_FALSE, glm::value_ptr(spatulaHeadModel));
	glUniformMatrix4fv(spatulaViewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(spatulaProjLoc, 1, GL_FALSE, glm::value_ptr(projection));
	// Draws Spatula Head
	glBindVertexArray(gMesh.spatulaHeadVao);
	model = glm::mat4(1.0f);
	// Bind textures
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, gSpatulaHeadTexture);
	// Draw Spatula Head
	glDrawArrays(GL_TRIANGLES, 0, gMesh.nSpatulaHeadVertices);
	//////////////////////////////////
	// Spatula Two Head
	// Scale, rotate, and translate bottle
	glm::mat4 spatulaTwoScale = glm::scale(glm::vec3(1.0f, 2.0f, 1.0f));
	glm::mat4 spatulaTwoRotation = glm::rotate(-4.7f, glm::vec3(0.0, 1.0f, 0.0f));
	glm::mat4 spatulaTwoTranslation = glm::translate(glm::vec3(-0.5f, -0.67f, 1.0f));
	// Model matrix: transformations are applied right-to-left order
	glm::mat4 spatulaTwoModel = spatulaTwoTranslation * spatulaTwoRotation * spatulaTwoScale;
	// Retrieves and passes transform matrices to the Shader program
	GLint spatulaTwoModelLoc = glGetUniformLocation(gProgramId, "model");
	GLint spatulaTwoViewLoc = glGetUniformLocation(gProgramId, "view");
	GLint spatulaTwoProjLoc = glGetUniformLocation(gProgramId, "projection");
	glUniformMatrix4fv(spatulaTwoModelLoc, 1, GL_FALSE, glm::value_ptr(spatulaTwoModel));
	glUniformMatrix4fv(spatulaTwoViewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(spatulaTwoProjLoc, 1, GL_FALSE, glm::value_ptr(projection));
	// Draws Spatula
	glBindVertexArray(gMesh.spatulaTwoVao);
	model = glm::mat4(1.0f);
	// Bind textures
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, gSpatulaTwoTexture);
	// Draw Spatula
	glDrawArrays(GL_TRIANGLES, 0, gMesh.nSpatulaTwoVertices);
	//////////////////////////////////
	// Spatula Two Head
	// Scale, rotate, and translate bottle
	glm::mat4 spatulaTwoHeadScale = glm::scale(glm::vec3(0.16f, 0.02f, 0.14f));
	glm::mat4 spatulaTwoHeadRotation = glm::rotate(-4.7f, glm::vec3(0.0, 1.0f, 0.0f));
	glm::mat4 spatulaTwoHeadTranslation = glm::translate(glm::vec3(-0.5f, -0.75f, -1.0f));
	// Model matrix: transformations are applied right-to-left order
	glm::mat4 spatulaTwoHeadModel = spatulaTwoHeadTranslation * spatulaTwoHeadRotation * spatulaTwoHeadScale;
	// Retrieves and passes transform matrices to the Shader program
	GLint spatulaTwoHeadModelLoc = glGetUniformLocation(gProgramId, "model");
	GLint spatulaTwoHeadViewLoc = glGetUniformLocation(gProgramId, "view");
	GLint spatulaTwoHeadProjLoc = glGetUniformLocation(gProgramId, "projection");
	glUniformMatrix4fv(spatulaTwoHeadModelLoc, 1, GL_FALSE, glm::value_ptr(spatulaTwoHeadModel));
	glUniformMatrix4fv(spatulaTwoHeadViewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(spatulaTwoHeadProjLoc, 1, GL_FALSE, glm::value_ptr(projection));
	// Draws Spatula
	glBindVertexArray(gMesh.spatulaTwoHeadVao);
	model = glm::mat4(1.0f);
	// Bind textures
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, gSpatulaTwoHeadTexture);
	// Draw Spatula
	glDrawArrays(GL_TRIANGLES, 0, gMesh.nSpatulaTwoHeadVertices);
	//////////////////////////////////
	// Bottle
	// Scale, rotate, and translate bottle
	glm::mat4 bottleScale = glm::scale(glm::vec3(1.0f, 2.0f, 1.0f));
	glm::mat4 bottleRotation = glm::rotate(-25.13f, glm::vec3(0.0, 1.0f, 0.0f));
	glm::mat4 bottleTranslation = glm::translate(glm::vec3(1.0f, 0.0f, -1.5f));
	// Model matrix: transformations are applied right-to-left order
	glm::mat4 bottleModel = bottleTranslation * bottleRotation * bottleScale;
	// Retrieves and passes transform matrices to the Shader program
	GLint bottleModelLoc = glGetUniformLocation(gProgramId, "model");
	GLint bottleViewLoc = glGetUniformLocation(gProgramId, "view");
	GLint bottleProjLoc = glGetUniformLocation(gProgramId, "projection");
	glUniformMatrix4fv(bottleModelLoc, 1, GL_FALSE, glm::value_ptr(bottleModel));
	glUniformMatrix4fv(bottleViewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(bottleProjLoc, 1, GL_FALSE, glm::value_ptr(projection));
	// Draws bottle
	glBindVertexArray(gMesh.bottleVao);
	model = glm::mat4(1.0f);
	// Bind textures
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, gBottleTexture);
	// Draw bottle
	glDrawArrays(GL_TRIANGLES, 0, gMesh.nBottleVertices);
	/////////////////
	//// Bottle Neck
	// Scale, rotate, and translate bottle neck
	glm::mat4 bottleNeckScale = glm::scale(glm::vec3(0.06f, 0.1f, 0.06f));
	glm::mat4 bottleNeckRotation = glm::rotate(-25.0f, glm::vec3(0.0, 1.0f, 0.0f));
	glm::mat4 bottleNeckTranslation = glm::translate(glm::vec3(1.0f, 1.0f, -1.5f));
	// Model matrix: transformations are applied right-to-left order
	glm::mat4 bottleNeckModel = bottleNeckTranslation * bottleNeckRotation * bottleNeckScale;
	// Retrieves and passes transform matrices to the Shader program
	GLint bottleNeckModelLoc = glGetUniformLocation(gProgramId, "model");
	GLint bottleNeckViewLoc = glGetUniformLocation(gProgramId, "view");
	GLint bottleNeckProjLoc = glGetUniformLocation(gProgramId, "projection");
	glUniformMatrix4fv(bottleNeckModelLoc, 1, GL_FALSE, glm::value_ptr(bottleNeckModel));
	glUniformMatrix4fv(bottleNeckViewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(bottleNeckProjLoc, 1, GL_FALSE, glm::value_ptr(projection));
	// Activate the VBOs contained within the mesh's VAO
	glBindVertexArray(gMesh.bottleNeckVao);
	model = glm::mat4(1.0f);
	// Bind textures
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, gBottleNeckTexture);
	// Draws the triangles
	glDrawArrays(GL_TRIANGLES, 0, gMesh.nBottleNeckVertices);
	/////////////////
	//// Seasoning
	// Scale, rotate, and translate seasoning
	glm::mat4 seasoningScale = glm::scale(glm::vec3(0.05f, 0.06f, 0.05f));
	glm::mat4 seasoningRotation = glm::rotate(-25.0f, glm::vec3(0.0, 1.0f, 0.0f));
	glm::mat4 seasoningTranslation = glm::translate(glm::vec3(1.3f, -1.0f, -0.7f));
	// Model matrix: transformations are applied right-to-left order
	glm::mat4 seasoningModel = seasoningTranslation * seasoningRotation * seasoningScale;
	// Retrieves and passes transform matrices to the Shader program
	GLint seasoningModelLoc = glGetUniformLocation(gProgramId, "model");
	GLint seasoningViewLoc = glGetUniformLocation(gProgramId, "view");
	GLint seasoningProjLoc = glGetUniformLocation(gProgramId, "projection");
	glUniformMatrix4fv(seasoningModelLoc, 1, GL_FALSE, glm::value_ptr(seasoningModel));
	glUniformMatrix4fv(seasoningViewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(seasoningProjLoc, 1, GL_FALSE, glm::value_ptr(projection));
	// Activate the VBOs contained within the mesh's VAO
	glBindVertexArray(gMesh.seasoningVao);
	model = glm::mat4(1.0f);
	// Bind textures
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, gSeasoningTexture);
	// Draws the triangles
	glDrawArrays(GL_TRIANGLES, 0, gMesh.nSeasoningVertices);
	/////////////////
	//// Seasoning Neck
	// Scale, rotate, and translate seasoning
	glm::mat4 seasoningNeckScale = glm::scale(glm::vec3(0.04f, 0.02f, 0.04f));
	glm::mat4 seasoningNeckRotation = glm::rotate(-25.0f, glm::vec3(0.0, 1.0f, 0.0f));
	glm::mat4 seasoningNeckTranslation = glm::translate(glm::vec3(1.3f, -0.4f, -0.7f));
	// Model matrix: transformations are applied right-to-left order
	glm::mat4 seasoningNeckModel = seasoningNeckTranslation * seasoningNeckRotation * seasoningNeckScale;
	// Retrieves and passes transform matrices to the Shader program
	GLint seasoningNeckModelLoc = glGetUniformLocation(gProgramId, "model");
	GLint seasoningNeckViewLoc = glGetUniformLocation(gProgramId, "view");
	GLint seasoningNeckProjLoc = glGetUniformLocation(gProgramId, "projection");
	glUniformMatrix4fv(seasoningNeckModelLoc, 1, GL_FALSE, glm::value_ptr(seasoningNeckModel));
	glUniformMatrix4fv(seasoningNeckViewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(seasoningNeckProjLoc, 1, GL_FALSE, glm::value_ptr(projection));
	// Activate the VBOs contained within the mesh's VAO
	glBindVertexArray(gMesh.seasoningNeckVao);
	model = glm::mat4(1.0f);
	// Bind textures
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, gSeasoningNeckTexture);
	// Draws the triangles
	glDrawArrays(GL_TRIANGLES, 0, gMesh.nSeasoningNeckVertices);
	/////////////////
	//// Seasoning Top
	// Scale, rotate, and translate seasoning
	glm::mat4 seasoningTopScale = glm::scale(glm::vec3(0.05f, 0.02f, 0.05f));
	glm::mat4 seasoningTopRotation = glm::rotate(-25.0f, glm::vec3(0.0, 1.0f, 0.0f));
	glm::mat4 seasoningTopTranslation = glm::translate(glm::vec3(1.3f, -0.2f, -0.7f));
	// Model matrix: transformations are applied right-to-left order
	glm::mat4 seasoningTopModel = seasoningTopTranslation * seasoningTopRotation * seasoningTopScale;
	// Retrieves and passes transform matrices to the Shader program
	GLint seasoningTopModelLoc = glGetUniformLocation(gProgramId, "model");
	GLint seasoningTopViewLoc = glGetUniformLocation(gProgramId, "view");
	GLint seasoningTopProjLoc = glGetUniformLocation(gProgramId, "projection");
	glUniformMatrix4fv(seasoningTopModelLoc, 1, GL_FALSE, glm::value_ptr(seasoningTopModel));
	glUniformMatrix4fv(seasoningTopViewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(seasoningTopProjLoc, 1, GL_FALSE, glm::value_ptr(projection));
	// Activate the VBOs contained within the mesh's VAO
	glBindVertexArray(gMesh.seasoningTopVao);
	model = glm::mat4(1.0f);
	// Bind textures
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, gSeasoningTopTexture);
	// Draws the triangles
	glDrawArrays(GL_TRIANGLES, 0, gMesh.nSeasoningTopVertices);
	/////////////////
	//// Seasoning Two
	// Scale, rotate, and translate seasoning
	glm::mat4 seasoningTwoScale = glm::scale(glm::vec3(0.05f, 0.06f, 0.05f));
	glm::mat4 seasoningTwoRotation = glm::rotate(-25.0f, glm::vec3(0.0, 1.0f, 0.0f));
	glm::mat4 seasoningTwoTranslation = glm::translate(glm::vec3(0.7f, -1.0f, -0.7f));
	// Model matrix: transformations are applied right-to-left order
	glm::mat4 seasoningTwoModel = seasoningTwoTranslation * seasoningTwoRotation * seasoningTwoScale;
	// Retrieves and passes transform matrices to the Shader program
	GLint seasoningTwoModelLoc = glGetUniformLocation(gProgramId, "model");
	GLint seasoningTwoViewLoc = glGetUniformLocation(gProgramId, "view");
	GLint seasoningTwoProjLoc = glGetUniformLocation(gProgramId, "projection");
	glUniformMatrix4fv(seasoningTwoModelLoc, 1, GL_FALSE, glm::value_ptr(seasoningTwoModel));
	glUniformMatrix4fv(seasoningTwoViewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(seasoningTwoProjLoc, 1, GL_FALSE, glm::value_ptr(projection));
	// Activate the VBOs contained within the mesh's VAO
	glBindVertexArray(gMesh.seasoningTwoVao);
	model = glm::mat4(1.0f);
	// Bind textures
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, gSeasoningTwoTexture);
	// Draws the triangles
	glDrawArrays(GL_TRIANGLES, 0, gMesh.nSeasoningTwoVertices);
	/////////////////
	//// Seasoning Two Neck
	// Scale, rotate, and translate seasoning
	glm::mat4 seasoningTwoNeckScale = glm::scale(glm::vec3(0.04f, 0.02f, 0.04f));
	glm::mat4 seasoningTwoNeckRotation = glm::rotate(-25.0f, glm::vec3(0.0, 1.0f, 0.0f));
	glm::mat4 seasoningTwoNeckTranslation = glm::translate(glm::vec3(0.7f, -0.4f, -0.7f));
	// Model matrix: transformations are applied right-to-left order
	glm::mat4 seasoningTwoNeckModel = seasoningTwoNeckTranslation * seasoningTwoNeckRotation * seasoningTwoNeckScale;
	// Retrieves and passes transform matrices to the Shader program
	GLint seasoningTwoNeckModelLoc = glGetUniformLocation(gProgramId, "model");
	GLint seasoningTwoNeckViewLoc = glGetUniformLocation(gProgramId, "view");
	GLint seasoningTwoNeckProjLoc = glGetUniformLocation(gProgramId, "projection");
	glUniformMatrix4fv(seasoningTwoNeckModelLoc, 1, GL_FALSE, glm::value_ptr(seasoningTwoNeckModel));
	glUniformMatrix4fv(seasoningTwoNeckViewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(seasoningTwoNeckProjLoc, 1, GL_FALSE, glm::value_ptr(projection));
	// Activate the VBOs contained within the mesh's VAO
	glBindVertexArray(gMesh.seasoningTwoNeckVao);
	model = glm::mat4(1.0f);
	// Bind textures
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, gSeasoningTwoNeckTexture);
	// Draws the triangles
	glDrawArrays(GL_TRIANGLES, 0, gMesh.nSeasoningTwoNeckVertices);
	/////////////////
	//// Seasoning Top
	// Scale, rotate, and translate seasoning
	glm::mat4 seasoningTwoTopScale = glm::scale(glm::vec3(0.05f, 0.02f, 0.05f));
	glm::mat4 seasoningTwoTopRotation = glm::rotate(-25.0f, glm::vec3(0.0, 1.0f, 0.0f));
	glm::mat4 seasoningTwoTopTranslation = glm::translate(glm::vec3(0.7f, -0.2f, -0.7f));
	// Model matrix: transformations are applied right-to-left order
	glm::mat4 seasoningTwoTopModel = seasoningTwoTopTranslation * seasoningTwoTopRotation * seasoningTwoTopScale;
	// Retrieves and passes transform matrices to the Shader program
	GLint seasoningTwoTopModelLoc = glGetUniformLocation(gProgramId, "model");
	GLint seasoningTwoTopViewLoc = glGetUniformLocation(gProgramId, "view");
	GLint seasoningTwoTopProjLoc = glGetUniformLocation(gProgramId, "projection");
	glUniformMatrix4fv(seasoningTwoTopModelLoc, 1, GL_FALSE, glm::value_ptr(seasoningTwoTopModel));
	glUniformMatrix4fv(seasoningTwoTopViewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(seasoningTwoTopProjLoc, 1, GL_FALSE, glm::value_ptr(projection));
	// Activate the VBOs contained within the mesh's VAO
	glBindVertexArray(gMesh.seasoningTwoTopVao);
	model = glm::mat4(1.0f);
	// Bind textures
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, gSeasoningTwoTopTexture);
	// Draws the triangles
	glDrawArrays(GL_TRIANGLES, 0, gMesh.nSeasoningTwoTopVertices);
	///////////////////////////////////
	// Lamp
	// ----------------------------------------------------
	// Scale, rotate, and translate bottle
	glUseProgram(gLampProgramId);
	glm::mat4 lightScale = glm::scale(glm::vec3(0.3f, 0.3f, 0.3f));
	glm::mat4 lightRotation = glm::rotate(glm::radians(45.0f), glm::vec3(0.0, 1.0f, 0.0f));
	glm::mat4 lightTranslation = glm::translate(glm::vec3(2.0f, 5.0f, 0.0f));
	// Model matrix: transformations are applied right-to-left order
	glm::mat4 lightModel = lightTranslation * lightRotation * lightScale;
	// Retrieves and passes transform matrices to the Shader program
	GLint lightModelLoc = glGetUniformLocation(gLampProgramId, "model");
	GLint lightViewLoc = glGetUniformLocation(gLampProgramId, "view");
	GLint lightProjLoc = glGetUniformLocation(gLampProgramId, "projection");
	glUniformMatrix4fv(lightModelLoc, 1, GL_FALSE, glm::value_ptr(lightModel));
	glUniformMatrix4fv(lightViewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(lightProjLoc, 1, GL_FALSE, glm::value_ptr(projection));

	// Draws bottle
	glBindVertexArray(gMesh.vao[2]);
	model = glm::mat4(1.0f);
	// Draw bottle
	glDrawArrays(GL_TRIANGLES, 0, gMesh.nVertices[2]);
	/////////////////
	// Deactivate the Vertex Array Object
	glBindVertexArray(0);
	// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
	glfwSwapBuffers(gWindow); // Flips the the back buffer with the front buffer every frame.
}
// Implements the UCreateMesh function
void UCreateTexturedMesh(GLMesh& mesh)
{
	// Position and texture data
	GLfloat verts[] = {
		//Positions //Normals
		// ------------------------------------------------------
		//Back Face				//Negative Z Normal		Texture Coords.
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f, -1.0f,		0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,	0.0f, 0.0f, -1.0f,		1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,	0.0f, 0.0f, -1.0f,		1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,	0.0f, 0.0f, -1.0f,		1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,	0.0f, 0.0f, -1.0f,		0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f, -1.0f,		0.0f, 0.0f,
		//Front Face			//Positive Z Normal
		-0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 1.0f,		0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 1.0f,		1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 1.0f,		1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 1.0f,		1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 1.0f,		0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 1.0f,		0.0f, 0.0f,
		//Left Face				//Negative X Normal
		-0.5f,  0.5f,  0.5f,   -1.0f, 0.0f, 0.0f,		1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,   -1.0f, 0.0f, 0.0f,		1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,   -1.0f, 0.0f, 0.0f,		0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,   -1.0f, 0.0f, 0.0f,		0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,   -1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,   -1.0f, 0.0f, 0.0f,		1.0f, 0.0f,
		//Right Face			//Positive X Normal
		 0.5f,  0.5f,  0.5f,    1.0f, 0.0f, 0.0f,		1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,    1.0f, 0.0f, 0.0f,		1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,    1.0f, 0.0f, 0.0f,		0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,    1.0f, 0.0f, 0.0f,		0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,    1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,    1.0f, 0.0f, 0.0f,		1.0f, 0.0f,
		 //Bottom Face			//Negative Y Normal
		 -0.5f, -0.5f, -0.5f,	0.0f, -1.0f, 0.0f,		0.0f, 1.0f,
		  0.5f, -0.5f, -0.5f,	0.0f, -1.0f, 0.0f,		1.0f, 1.0f,
		  0.5f, -0.5f,  0.5f,	0.0f, -1.0f, 0.0f,		1.0f, 0.0f,
		  0.5f, -0.5f,  0.5f,	0.0f, -1.0f, 0.0f,		1.0f, 0.0f,
		 -0.5f, -0.5f,  0.5f,	0.0f, -1.0f, 0.0f,		0.0f, 0.0f,
		 -0.5f, -0.5f, -0.5f,	0.0f, -1.0f, 0.0f,		0.0f, 1.0f,
		 //Top Face				//Positive Y Normal
		 -0.5f, 0.5f, -0.5f,		0.0f, 1.0f, 0.0f,		0.0f, 1.0f,
		  0.5f, 0.5f, -0.5f,		0.0f, 1.0f, 0.0f,		1.0f, 1.0f,
		  0.5f, 0.5f,  0.5f,		0.0f, 1.0f, 0.0f,		1.0f, 0.0f,
		  0.5f, 0.5f,  0.5f,		0.0f, 1.0f, 0.0f,		1.0f, 0.0f,
		 -0.5f, 0.5f,  0.5f,		0.0f, 1.0f, 0.0f,		0.0f, 0.0f,
		 -0.5f, 0.5f, -0.5f,		0.0f, 1.0f, 0.0f,		0.0f, 1.0f
	};
	GLfloat planeVerts[] = {
		// Vertex Positions		// Texture coordinates
		-5.0f, -5.0f, -5.0f,	-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 5.0f, -5.0f, -5.0f,	0.0f, 1.0f, 0.0f,	1.0f, 0.0f,

		 5.0f, -5.0f,  5.0f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 5.0f, -5.0f,  5.0f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		-5.0f, -5.0f,  5.0f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-5.0f, -5.0f, -5.0f,	-1.0f, 0.0f, 0.0f,	0.0f, 0.0f
	};
	GLfloat potHolderVerts[] = {
		// Vertex Positions		// Texture coordinates
		-1.5f, -1.5f, -1.5f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 1.5f, -1.5f, -1.5f,	0.0f, 1.0f, 0.0f,	1.0f, 0.0f,

		 1.5f, -1.5f,  1.5f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 1.5f, -1.5f,  1.5f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		-1.5f, -1.5f,  1.5f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-1.5f, -1.5f, -1.5f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f
	};
	GLfloat spatulaVerts[] = {
		// Spatula body
		 // Vertex Positons		// Normals			// Texture
		-1.5f,  0.05f, -0.1f,	0.0f, -1.0f, 0.0f,	0.0f, 1.0f,
		
		 1.5f,  0.05f, -0.1f,	0.0f, -1.0f, 0.0f,	1.0f, 1.0f,
		
		-1.5f, -0.05f, -0.1f,	0.0f, -1.0f, 0.0f,	0.0f, 0.0f,
		
		 1.5f, -0.05f, -0.1f,	0.0f, -1.0f, 0.0f,	0.0f, 1.0f,
		
		-1.5f, -0.05f, -0.1f,	0.0f, -1.0f, 0.0f,	1.0f, 1.0f,
		
		 1.5f,  0.05f, -0.1f,	0.0f, -1.0f, 0.0f,	0.0f, 0.0f,
		
		-1.5f,  0.05f, 0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,
		 
		 1.5f,  0.05f, 0.1f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,
		
		-1.5f, -0.05f, 0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,
		
		 1.5f, -0.05f, 0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,
		
		-1.5f, -0.05f, 0.1f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,
		
		 1.5f,  0.05f, 0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,
		 
		-1.5f,  0.05f,  0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,
		
		-1.5f,  0.05f, -0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,
		
		-1.5f, -0.05f, -0.1f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,
		
		-1.5f, -0.05f, -0.1f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,
		
		-1.5f, -0.05f,  0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,
		
		-1.5f,  0.05f,  0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,
		
		-1.5f, -0.05f,  0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,
		
		-1.5f, -0.05f, -0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,
		
		 1.5f, -0.05f, -0.1f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,
		
		 1.5f, -0.05f,  0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,
		
		-1.5f, -0.05f,  0.1f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,
		
		 1.5f, -0.05f, -0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,
		
		-1.5f, 0.05f,  0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,
		
		-1.5f, 0.05f, -0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,
		
		 1.5f, 0.05f, -0.1f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,
		
		 1.5f, 0.05f,  0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,
		
		-1.5f, 0.05f,  0.1f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,
		
		 1.5f, 0.05f, -0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,
		
		 1.5f,  0.05f,  0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,
		
		 1.5f,  0.05f, -0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,
		
		 1.5f, -0.05f, -0.1f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,
		
		 1.5f, -0.05f, -0.1f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,
		
		 1.5f, -0.05f,  0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,
		
		 1.5f,  0.05f,  0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,
	};
	GLfloat spatulaHeadVerts[] = {
		// Vertex Positions		// Normals					// Texture coordinates
		-0.5f, -0.5f, -0.5f,	-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 0.5f, -0.5f, -0.5f,	-1.0f, 0.0f, 0.0f,	1.0f, 0.0f,

		 0.5f,  0.5f, -0.5f,	-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		 0.5f,  0.5f, -0.5f,	-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,	-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		-0.5f, -0.5f, -0.5f,	-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.5f, -0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		-0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-0.5f, -0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 0.0f,

		-0.5f,  0.5f, -0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-0.5f, -0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 0.0f,

		 0.5f,  0.5f, -0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.5f, -0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.5f, -0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 0.0f,

		 0.5f, -0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,	-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		 0.5f,  0.5f, -0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		-0.5f,  0.5f, -0.5f,	-1.0f, 0.0f, 0.0f,	0.0f, 1.0f
	};
	GLfloat spatulaTwoVerts[] = {
		// Spatula Two body
		 // Vertex Positons		// Normals			// Texture
		-1.5f,  0.05f, -0.1f,	0.0f, -1.0f, 0.0f,	0.0f, 1.0f,
		 
		 1.5f,  0.05f, -0.1f,	0.0f, -1.0f, 0.0f,	1.0f, 1.0f,
		
		-1.5f, -0.05f, -0.1f,	0.0f, -1.0f, 0.0f,	0.0f, 0.0f,
		 
		 1.5f, -0.05f, -0.1f,	0.0f, -1.0f, 0.0f,	0.0f, 1.0f,
		
		-1.5f, -0.05f, -0.1f,	0.0f, -1.0f, 0.0f,	1.0f, 1.0f,
		 
		 1.5f,  0.05f, -0.1f,	0.0f, -1.0f, 0.0f,	0.0f, 0.0f,
		
		-1.5f,  0.05f, 0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,
		  
		 1.5f,  0.05f, 0.1f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,
		 
		-1.5f, -0.05f, 0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,
		  
		 1.5f, -0.05f, 0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,
		 
		-1.5f, -0.05f, 0.1f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,
		  
		 1.5f,  0.05f, 0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,
		
		-1.5f,  0.05f,  0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,
		 
		-1.5f,  0.05f, -0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,
		 
		-1.5f, -0.05f, -0.1f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,
		 
		-1.5f, -0.05f, -0.1f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,
		 
		-1.5f, -0.05f,  0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,
		 
		-1.5f,  0.05f,  0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,
		
		-1.5f, -0.05f,  0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,
		 
		-1.5f, -0.05f, -0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,
		 
		 1.5f, -0.05f, -0.1f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,
		 
		 1.5f, -0.05f,  0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,
		 
		-1.5f, -0.05f,  0.1f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,
		 
		 1.5f, -0.05f, -0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,
		
		-1.5f, 0.05f,  0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,
		  
		-1.5f, 0.05f, -0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,
		  
		 1.5f, 0.05f, -0.1f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,
		  
		 1.5f, 0.05f,  0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,
		  
		-1.5f, 0.05f,  0.1f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,
		  
		 1.5f, 0.05f, -0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,
		
		 1.5f,  0.05f,  0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,
		   
		 1.5f,  0.05f, -0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,
		   
		 1.5f, -0.05f, -0.1f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,
		   
		 1.5f, -0.05f, -0.1f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,
		   
		 1.5f, -0.05f,  0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,
		   
		 1.5f,  0.05f,  0.1f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,
	};
	GLfloat spatulaTwoHeadVerts[] = {
		// Vertex Positions		// Texture coordinates
		-3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		-4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		-3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 0.0f, -4.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 10.0f,-4.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 10.0f,-4.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f,-4.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-4.0f, 10.0f, 0.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-4.0f, 10.0f, 0.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-4.0f, 0.0f,  0.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-3.0f, 0.0f,  3.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 0.0f,  3.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-4.0f, 10.0f, 0.0f,		-1.0f, 0.0f, 0.0f,   0.0f, 0.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f,-4.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 0.0f, 10.0f,-4.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		-4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		-4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,
	};
	GLfloat bottleVert[] = {
		// Vertex Positions		// Texture coordinates
		-0.5f, -0.5f, -0.5f,	-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 0.5f, -0.5f, -0.5f,	-1.0f, 0.0f, 0.0f,	1.0f, 0.0f,

		 0.5f,  0.5f, -0.5f,	-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		 0.5f,  0.5f, -0.5f,	-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,	-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		-0.5f, -0.5f, -0.5f,	-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,	-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 0.5f, -0.5f,  0.5f,	-1.0f, 0.0f, 0.0f,	1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		-0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-0.5f, -0.5f,  0.5f,	-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,	-1.0f, 0.0f, 0.0f,	1.0f, 0.0f,

		-0.5f,  0.5f, -0.5f,	-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		-0.5f, -0.5f, -0.5f,	-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		-0.5f, -0.5f, -0.5f,	-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		-0.5f, -0.5f,  0.5f,	-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,	-1.0f, 0.0f, 0.0f,	1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,	-1.0f, 0.0f, 0.0f,	1.0f, 0.0f,

		 0.5f,  0.5f, -0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.5f, -0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.5f, -0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 0.0f,

		 0.5f, -0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,	-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		 0.5f,  0.5f, -0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	1.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		-0.5f,  0.5f, -0.5f,	-1.0f, 0.0f, 0.0f,	0.0f, 1.0f
	};
	GLfloat bottleNeckVerts[] = {
		// Vertex Positions		// Texture coordinates
		-3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		-3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 10.0f,-4.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 10.0f,-4.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 0.0f, -4.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f,-4.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-4.0f, 10.0f, 0.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-4.0f, 10.0f, 0.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-4.0f, 0.0f,  0.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-3.0f, 0.0f,  3.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 0.0f,  3.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-4.0f, 10.0f, 0.0f,		-1.0f, 0.0f, 0.0f,    0.0f, 0.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f,-4.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 0.0f, 10.0f,-4.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		-4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		-4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,
	};
	GLfloat seasoningVerts[] = {
		// Vertex Positions		// Texture coordinates
		-3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		-3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 10.0f,-4.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 10.0f,-4.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 0.0f, -4.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f,-4.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-4.0f, 10.0f, 0.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-4.0f, 10.0f, 0.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-4.0f, 0.0f,  0.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-3.0f, 0.0f,  3.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 0.0f,  3.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-4.0f, 10.0f, 0.0f,		-1.0f, 0.0f, 0.0f,    0.0f, 0.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f,-4.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 0.0f, 10.0f,-4.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		-4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		-4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,
	};
	GLfloat seasoningNeckVerts[] = {
		// Vertex Positions		// Texture coordinates
		-3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		-3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 10.0f,-4.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 10.0f,-4.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 0.0f, -4.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f,-4.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-4.0f, 10.0f, 0.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-4.0f, 10.0f, 0.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-4.0f, 0.0f,  0.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-3.0f, 0.0f,  3.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 0.0f,  3.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-4.0f, 10.0f, 0.0f,		-1.0f, 0.0f, 0.0f,    0.0f, 0.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f,-4.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 0.0f, 10.0f,-4.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		-4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		-4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,
	};
	GLfloat seasoningTopVerts[] = {
		// Vertex Positions		// Texture coordinates
		-3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		-3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 10.0f,-4.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 10.0f,-4.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 0.0f, -4.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f,-4.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-4.0f, 10.0f, 0.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-4.0f, 10.0f, 0.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-4.0f, 0.0f,  0.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-3.0f, 0.0f,  3.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 0.0f,  3.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-4.0f, 10.0f, 0.0f,		-1.0f, 0.0f, 0.0f,    0.0f, 0.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f,-4.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 0.0f, 10.0f,-4.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		-4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		-4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,
	};
	GLfloat seasoningTwoVerts[] = {
		// Vertex Positions		// Texture coordinates
		-3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		-3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 10.0f,-4.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 10.0f,-4.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 0.0f, -4.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f,-4.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-4.0f, 10.0f, 0.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-4.0f, 10.0f, 0.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-4.0f, 0.0f,  0.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-3.0f, 0.0f,  3.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 0.0f,  3.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-4.0f, 10.0f, 0.0f,		-1.0f, 0.0f, 0.0f,    0.0f, 0.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f,-4.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 0.0f, 10.0f,-4.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		-4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		-4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,
	};
	GLfloat seasoningTwoNeckVerts[] = {
		// Vertex Positions		// Texture coordinates
		-3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		-3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 10.0f,-4.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 10.0f,-4.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 0.0f, -4.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f,-4.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-4.0f, 10.0f, 0.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-4.0f, 10.0f, 0.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-4.0f, 0.0f,  0.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-3.0f, 0.0f,  3.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 0.0f,  3.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-4.0f, 10.0f, 0.0f,		-1.0f, 0.0f, 0.0f,    0.0f, 0.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f,-4.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 0.0f, 10.0f,-4.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		-4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		-4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,
	};
	GLfloat seasoningTwoTopVerts[] = {
		// Vertex Positions		// Texture coordinates
		-3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		-3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 0.0f,  4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 0.0f,  3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 4.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 0.0f, -3.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 0.0f, -4.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		 0.0f, 10.0f,-4.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 10.0f,-4.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

		 0.0f, 0.0f, -4.0f,		-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		-3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f,-4.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-3.0f, 0.0f, -3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-4.0f, 0.0f,  0.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-4.0f, 10.0f, 0.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-4.0f, 10.0f, 0.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 0.0f,

		-4.0f, 0.0f,  0.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-3.0f, 0.0f,  3.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 0.0f,  3.0f,		-1.0f, 0.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		-1.0f, 0.0f, 0.0f,	 0.0f, 1.0f,

		-4.0f, 10.0f, 0.0f,		-1.0f, 0.0f, 0.0f,    0.0f, 0.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 4.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f,-4.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		 0.0f, 10.0f,-4.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f,-3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 0.0f,

		-4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,

		-4.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		 0.0f, 10.0f, 0.0f,		0.0f, 1.0f, 0.0f,	 1.0f, 1.0f,

		-3.0f, 10.0f, 3.0f,		0.0f, 1.0f, 0.0f,	 0.0f, 1.0f,
	};
	const GLuint floatsPerVertex = 3;
	const GLuint floatsPerNormal = 3;
	const GLuint floatsPerUV = 2;
	// Strides between vertex coordinates
	GLint stride = sizeof(float) * (floatsPerVertex + floatsPerNormal + floatsPerUV);// The number of floats before each
	// Plane
	// --------------------------
	mesh.nPlaneVertices = sizeof(planeVerts) / (sizeof(planeVerts[0]) * (floatsPerVertex + floatsPerNormal + floatsPerUV));
	glGenVertexArrays(1, &mesh.planeVao); // we can also generate multiple VAOs or buffers at the same time
	glBindVertexArray(mesh.planeVao);
	// Create VBO
	glGenBuffers(1, &mesh.planeVbo);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.planeVbo); // Activates the buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(planeVerts), planeVerts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU
	// Create Vertex Attribute Pointers
	glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float) * floatsPerVertex));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float) * (floatsPerVertex + floatsPerNormal)));
	glEnableVertexAttribArray(2);
	////////////////////////////////
	// Pot Holder
	// --------------------------
	mesh.nPotHolderVertices = sizeof(potHolderVerts) / (sizeof(potHolderVerts[0]) * (floatsPerVertex + floatsPerNormal + floatsPerUV));
	glGenVertexArrays(1, &mesh.potHolderVao); // we can also generate multiple VAOs or buffers at the same time
	glBindVertexArray(mesh.potHolderVao);
	// Create VBO
	glGenBuffers(1, &mesh.potHolderVbo);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.potHolderVbo); // Activates the buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(potHolderVerts), potHolderVerts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU
	// Create Vertex Attribute Pointers
	glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float)* floatsPerVertex));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float)* (floatsPerVertex + floatsPerNormal)));
	glEnableVertexAttribArray(2);
	////////////////////////////////
	// Spatula
	// --------------------------
	mesh.nSpatulaVertices = sizeof(spatulaVerts) / (sizeof(spatulaVerts[0]) * (floatsPerVertex + floatsPerNormal + floatsPerUV));
	glGenVertexArrays(1, &mesh.spatulaVao); // we can also generate multiple VAOs or buffers at the same time
	glBindVertexArray(mesh.spatulaVao);
	// Create VBO
	glGenBuffers(1, &mesh.spatulaVbo);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.spatulaVbo); // Activates the buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(spatulaVerts), spatulaVerts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU
	// Create Vertex Attribute Pointers
	glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float)* floatsPerVertex));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float)* (floatsPerVertex + floatsPerNormal)));
	glEnableVertexAttribArray(2);
	////////////////////////////////
	// Spatula Head
	// --------------------------
	mesh.nSpatulaHeadVertices = sizeof(spatulaHeadVerts) / (sizeof(spatulaHeadVerts[0]) * (floatsPerVertex + floatsPerNormal + floatsPerUV));
	glGenVertexArrays(1, &mesh.spatulaHeadVao); // we can also generate multiple VAOs or buffers at the same time
	glBindVertexArray(mesh.spatulaHeadVao);
	// Create VBO
	glGenBuffers(1, &mesh.spatulaHeadVbo);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.spatulaHeadVbo); // Activates the buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(spatulaHeadVerts), spatulaHeadVerts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU
	// Create Vertex Attribute Pointers
	glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float)* floatsPerVertex));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float)* (floatsPerVertex + floatsPerNormal)));
	glEnableVertexAttribArray(2);
	////////////////////////////////
	// Spatula Two
	// --------------------------
	mesh.nSpatulaTwoVertices = sizeof(spatulaTwoVerts) / (sizeof(spatulaTwoVerts[0]) * (floatsPerVertex + floatsPerNormal + floatsPerUV));
	glGenVertexArrays(1, &mesh.spatulaTwoVao); // we can also generate multiple VAOs or buffers at the same time
	glBindVertexArray(mesh.spatulaTwoVao);
	// Create VBO
	glGenBuffers(1, &mesh.spatulaTwoVbo);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.spatulaTwoVbo); // Activates the buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(spatulaTwoVerts), spatulaTwoVerts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU
	// Create Vertex Attribute Pointers
	glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float)* floatsPerVertex));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float)* (floatsPerVertex + floatsPerNormal)));
	glEnableVertexAttribArray(2);
	////////////////////////////////
	// Spatula Two
	// --------------------------
	mesh.nSpatulaTwoHeadVertices = sizeof(spatulaTwoHeadVerts) / (sizeof(spatulaTwoHeadVerts[0]) * (floatsPerVertex + floatsPerNormal + floatsPerUV));
	glGenVertexArrays(1, &mesh.spatulaTwoHeadVao); // we can also generate multiple VAOs or buffers at the same time
	glBindVertexArray(mesh.spatulaTwoHeadVao);
	// Create VBO
	glGenBuffers(1, &mesh.spatulaTwoHeadVbo);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.spatulaTwoHeadVbo); // Activates the buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(spatulaTwoHeadVerts), spatulaTwoHeadVerts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU
	// Create Vertex Attribute Pointers
	glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float)* floatsPerVertex));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float)* (floatsPerVertex + floatsPerNormal)));
	glEnableVertexAttribArray(2);
	////////////////////////////////
	// Bottle
	// --------------------------
	mesh.nBottleVertices = sizeof(bottleVert) / (sizeof(bottleVert[0]) * (floatsPerVertex + floatsPerNormal + floatsPerUV));
	glGenVertexArrays(1, &mesh.bottleVao);
	glBindVertexArray(mesh.bottleVao);
	//Create VBO
	glGenBuffers(1, &mesh.bottleVbos);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.bottleVbos);
	glBufferData(GL_ARRAY_BUFFER, sizeof(bottleVert), bottleVert, GL_STATIC_DRAW);
	// Create Vertex Attribute Pointers
	glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float) * floatsPerVertex));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float) * (floatsPerVertex + floatsPerNormal)));
	glEnableVertexAttribArray(2);
	/////////////////
	// Bottleneck
	// --------------------------
	mesh.nBottleNeckVertices = sizeof(bottleNeckVerts) / (sizeof(bottleNeckVerts[0]) * (floatsPerVertex + floatsPerNormal + floatsPerUV));
	glGenVertexArrays(1, &mesh.bottleNeckVao); // we can also generate multiple VAOs or buffers at the same time
	glBindVertexArray(mesh.bottleNeckVao);
	// Create VBO
	glGenBuffers(1, &mesh.bottleNeckVbo);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.bottleNeckVbo); // Activates the buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(bottleNeckVerts), bottleNeckVerts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU
	// Create Vertex Attribute Pointers
	glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float) * floatsPerVertex));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float) * (floatsPerVertex + floatsPerNormal)));
	glEnableVertexAttribArray(2);
	/////////////////
	// Seasoning
	// --------------------------
	mesh.nSeasoningVertices = sizeof(seasoningVerts) / (sizeof(seasoningVerts[0]) * (floatsPerVertex + floatsPerNormal + floatsPerUV));
	glGenVertexArrays(1, &mesh.seasoningVao); // we can also generate multiple VAOs or buffers at the same time
	glBindVertexArray(mesh.seasoningVao);
	// Create VBO
	glGenBuffers(1, &mesh.seasoningVbo);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.seasoningVbo); // Activates the buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(seasoningVerts), seasoningVerts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU
	// Create Vertex Attribute Pointers
	glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float)* floatsPerVertex));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float)* (floatsPerVertex + floatsPerNormal)));
	glEnableVertexAttribArray(2);
	/////////////////
	// Seasoning Neck
	// --------------------------
	mesh.nSeasoningNeckVertices = sizeof(seasoningNeckVerts) / (sizeof(seasoningNeckVerts[0]) * (floatsPerVertex + floatsPerNormal + floatsPerUV));
	glGenVertexArrays(1, &mesh.seasoningNeckVao); // we can also generate multiple VAOs or buffers at the same time
	glBindVertexArray(mesh.seasoningNeckVao);
	// Create VBO
	glGenBuffers(1, &mesh.seasoningNeckVbo);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.seasoningNeckVbo); // Activates the buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(seasoningNeckVerts), seasoningNeckVerts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU
	// Create Vertex Attribute Pointers
	glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float)* floatsPerVertex));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float)* (floatsPerVertex + floatsPerNormal)));
	glEnableVertexAttribArray(2);
	/////////////////
	// Seasoning Top
	// --------------------------
	mesh.nSeasoningTopVertices = sizeof(seasoningTopVerts) / (sizeof(seasoningTopVerts[0]) * (floatsPerVertex + floatsPerNormal + floatsPerUV));
	glGenVertexArrays(1, &mesh.seasoningTopVao); // we can also generate multiple VAOs or buffers at the same time
	glBindVertexArray(mesh.seasoningTopVao);
	// Create VBO
	glGenBuffers(1, &mesh.seasoningTopVbo);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.seasoningTopVbo); // Activates the buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(seasoningTopVerts), seasoningTopVerts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU
	// Create Vertex Attribute Pointers
	glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float)* floatsPerVertex));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float)* (floatsPerVertex + floatsPerNormal)));
	glEnableVertexAttribArray(2);
	/////////////////
	// Seasoning Two
	// --------------------------
	mesh.nSeasoningTwoVertices = sizeof(seasoningTwoVerts) / (sizeof(seasoningTwoVerts[0]) * (floatsPerVertex + floatsPerNormal + floatsPerUV));
	glGenVertexArrays(1, &mesh.seasoningTwoVao); // we can also generate multiple VAOs or buffers at the same time
	glBindVertexArray(mesh.seasoningTwoVao);
	// Create VBO
	glGenBuffers(1, &mesh.seasoningTwoVbo);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.seasoningTwoVbo); // Activates the buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(seasoningTwoVerts), seasoningTwoVerts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU
	// Create Vertex Attribute Pointers
	glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float)* floatsPerVertex));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float)* (floatsPerVertex + floatsPerNormal)));
	glEnableVertexAttribArray(2);
	/////////////////
	// Seasoning Two Neck
	// --------------------------
	mesh.nSeasoningTwoNeckVertices = sizeof(seasoningTwoNeckVerts) / (sizeof(seasoningTwoNeckVerts[0]) * (floatsPerVertex + floatsPerNormal + floatsPerUV));
	glGenVertexArrays(1, &mesh.seasoningTwoNeckVao); // we can also generate multiple VAOs or buffers at the same time
	glBindVertexArray(mesh.seasoningTwoNeckVao);
	// Create VBO
	glGenBuffers(1, &mesh.seasoningTwoNeckVbo);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.seasoningTwoNeckVbo); // Activates the buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(seasoningTwoNeckVerts), seasoningTwoNeckVerts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU
	// Create Vertex Attribute Pointers
	glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float)* floatsPerVertex));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float)* (floatsPerVertex + floatsPerNormal)));
	glEnableVertexAttribArray(2);
	/////////////////
	// Seasoning Two Top
	// --------------------------
	mesh.nSeasoningTwoTopVertices = sizeof(seasoningTwoTopVerts) / (sizeof(seasoningTwoTopVerts[0]) * (floatsPerVertex + floatsPerNormal + floatsPerUV));
	glGenVertexArrays(1, &mesh.seasoningTwoTopVao); // we can also generate multiple VAOs or buffers at the same time
	glBindVertexArray(mesh.seasoningTwoTopVao);
	// Create VBO
	glGenBuffers(1, &mesh.seasoningTwoTopVbo);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.seasoningTwoTopVbo); // Activates the buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(seasoningTwoTopVerts), seasoningTwoTopVerts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU
	// Create Vertex Attribute Pointers
	glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float)* floatsPerVertex));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float)* (floatsPerVertex + floatsPerNormal)));
	glEnableVertexAttribArray(2);
	////////////////////
	// Lamp
	// --------------------------
	mesh.nVertices[2] = sizeof(verts) / (sizeof(verts[0]) * (floatsPerVertex + floatsPerNormal + floatsPerUV));
	glGenVertexArrays(1, &mesh.vao[2]); // we can also generate multiple VAOs or buffers at the same time
	glBindVertexArray(mesh.vao[2]);
	// Create 2 buffers: first one for the vertex data; second one for the indices
	glGenBuffers(1, &mesh.vbo[2]);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.vbo[2]); // Activates the buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU
	// Create Vertex Attribute Pointers
	glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float) * floatsPerVertex));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float) * (floatsPerVertex + floatsPerNormal)));
	glEnableVertexAttribArray(2);
	////////////////////
}
void UDestroyMesh(GLMesh& mesh)
{
	glDeleteVertexArrays(3, mesh.vao);
	glDeleteBuffers(3, mesh.vbo);
}
/*Generate and load the texture*/
bool UCreateTexture(const char* filename, GLuint& textureId)
{
	int width, height, channels;
	unsigned char* image = stbi_load(filename, &width, &height, &channels, 0);
	if (image)
	{
		flipImageVertically(image, width, height, channels);
		glGenTextures(1, &textureId);
		glBindTexture(GL_TEXTURE_2D, textureId);
		// set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
			GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		if (channels == 3)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_RGB,
				GL_UNSIGNED_BYTE, image);
		else if (channels == 4)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA,
				GL_UNSIGNED_BYTE, image);
		else
		{
			cout << "Not implemented to handle image with " << channels << " channels" << endl;
			return false;
		}
		glGenerateMipmap(GL_TEXTURE_2D);
		stbi_image_free(image);
		glBindTexture(GL_TEXTURE_2D, 0); // Unbind the texture
		return true;
	}
	// Error loading the image
	return false;
}
void UDestroyTexture(GLuint textureId)
{
	glGenTextures(1, &textureId);
}
// Implements the UCreateShaders function
bool UCreateShaderProgram(const char* vtxShaderSource, const char*
	fragShaderSource, GLuint& programId)
{
	// Compilation and linkage error reporting
	int success = 0;
	char infoLog[512];
	// Create a Shader program object.
	programId = glCreateProgram();
	// Create the vertex and fragment shader objects
	GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	// Retrive the shader source
	glShaderSource(vertexShaderId, 1, &vtxShaderSource, NULL);
	glShaderSource(fragmentShaderId, 1, &fragShaderSource, NULL);
	// Compile the vertex shader, and print compilation errors (if any)
	glCompileShader(vertexShaderId); // compile the vertex shader
	// check for shader compile errors
	glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShaderId, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog <<
			std::endl;
		return false;
	}
	glCompileShader(fragmentShaderId); // compile the fragment shader
	// check for shader compile errors
	glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShaderId, sizeof(infoLog), NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog <<
			std::endl;
		return false;
	}
	// Attached compiled shaders to the shader program
	glAttachShader(programId, vertexShaderId);
	glAttachShader(programId, fragmentShaderId);
	glLinkProgram(programId); // links the shader program
	// check for linking errors
	glGetProgramiv(programId, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(programId, sizeof(infoLog), NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		return false;
	}
	glUseProgram(programId); // Uses the shader program
	return true;
}
void UDestroyShaderProgram(GLuint programId)
{
	glDeleteProgram(programId);
}