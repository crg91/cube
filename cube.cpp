/*
You are free to use this program anywhere!
Produced by Chirag Varde (twitter handle: _specular)
For any query mailto:chirag.varde.crg@gmail.com
*/
#include<iostream>
#include<GL/glew.h>
#include<GL/glut.h>
#include<fstream>
using namespace std;

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"

#define WIDTH	512
#define HEIGHT	512

//global identifiers
GLuint program_id;
GLuint vbo_id;
GLuint index_buffer_id;
glm::mat4 transformation_matrix;
float theta_x;
float theta_y;
float theta_z;

//array for position
GLfloat positions[8][4] = {
				-0.5, -0.5, 0.5, 1.0,
				0.5, -0.5, 0.5, 1.0,
				0.5, 0.5, 0.5, 1.0,
				-0.5, 0.5, 0.5, 1.0,
				-0.5, -0.5, -0.5, 1.0,
				0.5, -0.5, -0.5, 1.0,
				0.5, 0.5, -0.5, 1.0,
				-0.5, 0.5, -0.5, 1.0,
			};
//array for color
GLfloat colors[8][4] = {
				1.0, 0.0, 0.0, 1.0,
				0.0, 1.0, 0.0, 1.0,
				0.0, 0.0, 1.0, 1.0,
				0.5, 0.5, 0.5, 1.0,
				1.0, 1.0, 0.0, 1.0,
				0.0, 1.0, 1.0, 1.0,
				1.0, 0.0, 1.0, 1.0,
				0.5, 0.5, 0.5, 1.0,
			};

GLuint indices[36] =	{
				0, 1, 2, 0, 2, 3,
				5, 4, 6, 6, 4, 7,
				1, 5, 2, 2, 5, 6,
				0, 3, 4, 4, 3, 7,
				2, 6, 3, 3, 6, 7,
				0, 5, 1, 0, 4, 5
			};
//function prototypes
void initialize();
void display();
void key(unsigned char, int, int);
void create_matrix();
void create_program();
void create_vbo();
void bind_shader_variables();

void initialize()
{
	theta_x = 0.0;
	theta_y = 0.0;
	theta_z = 0.0;
	//background color is dark blue
	glClearColor(0.0, 0.0, 0.5, 0.0);

	//depth test is disabled by default
	glEnable(GL_DEPTH_TEST);

	//culling is disabled by default. Default front face is counter clock wise!!! By Default back face is culled
	glEnable(GL_CULL_FACE);

	create_program();
	create_vbo();
	create_matrix();
}

//callback function for rendering
void display()
{
	glUseProgram(program_id);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_id);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, NULL);
	glFlush();
	glutSwapBuffers();
}

//callback function for keyboard inputs
void key(unsigned char in_key, int x, int y)
{
	switch(in_key)
	{
		case 27: //escape character
			exit(0);
		case 'q':
			exit(0);
		case 'a':
			theta_x += 5.0;
			create_matrix();
			glutPostRedisplay();
			break;
		case 's':
			theta_x -= 5.0;
			create_matrix();
			glutPostRedisplay();
			break;
		case 'w':
			theta_y += 5.0;
			create_matrix();
			glutPostRedisplay();
			break;
		case 'e':
			theta_y -= 5.0;
			create_matrix();
			glutPostRedisplay();
			break;
		case 'z':
			theta_z += 5.0;
			create_matrix();
			glutPostRedisplay();
			break;
		case 'x':
			theta_z -= 5.0;
			create_matrix();
			glutPostRedisplay();
			break;
		default:
			break;
	}
}

//to fill up transformation matrix
void create_matrix()
{
	glm::mat4 scale_matrix = glm::mat4(1.0);

	glm::mat4 rotate_matrix = glm::mat4(1.0);
	rotate_matrix = glm::rotate(rotate_matrix, theta_x, glm::vec3(1.0, 0.0, 0.0));
	rotate_matrix = glm::rotate(rotate_matrix, theta_y, glm::vec3(0.0, 1.0, 0.0));
	rotate_matrix = glm::rotate(rotate_matrix, theta_z, glm::vec3(0.0, 0.0, 1.0));

	glm::mat4 translate_matrix = glm::mat4(1.0);

	transformation_matrix = translate_matrix*rotate_matrix*scale_matrix;
	bind_shader_variables();
}

//binding of shader variables
void bind_shader_variables()
{
	glUseProgram(program_id);
	//attributes
	GLuint pos_id = glGetAttribLocation(program_id, "in_position");
	GLuint col_id = glGetAttribLocation(program_id, "in_color");
	GLuint mat_id = glGetUniformLocation(program_id, "transformation_matrix");
#if 0
	cout<<"pos_id = "<<pos_id<<endl;
	cout<<"col_id = "<<col_id<<endl;
	cout<<"mat_id = "<<mat_id<<endl;
#endif
	glVertexAttribPointer(pos_id, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(pos_id);
	glVertexAttribPointer(col_id, 4, GL_FLOAT, GL_FALSE, 0, (void*)(sizeof(GLfloat)*32));
	glEnableVertexAttribArray(col_id);
	
	glUniformMatrix4fv(mat_id, 1, GL_FALSE, glm::value_ptr(transformation_matrix));
}

void create_vbo()
{
	glGenBuffers(1, &vbo_id);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*32*2, 0, GL_STATIC_DRAW);

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat)*32, positions);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(GLfloat)*32, sizeof(GLfloat)*32, colors);

	glGenBuffers(1, &index_buffer_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int)*36, indices, GL_STATIC_DRAW);
}

void create_program()
{
	GLint status; //to check compile and linking status

	//compile vertex shader
	ifstream vertex_shader_file;
	int vertex_shader_length;
	vertex_shader_file.open("simple_shader.vert", ios::in);
	//go to end of the file to get total characters in the file
	vertex_shader_file.seekg(0, ios::end);
	vertex_shader_length = vertex_shader_file.tellg();
	vertex_shader_file.seekg(0, ios::beg);
	//allocated temporary character array for shader source
	char* vertex_shader_source = new char[vertex_shader_length + 1];//one extra character is for NULL
	vertex_shader_file.read(vertex_shader_source, vertex_shader_length);
	vertex_shader_source[vertex_shader_length] = '\0';
#if 0
	for(int i = 0; i<vertex_shader_length; i++)
		cout<<vertex_shader_source[i];
	cout<<endl;
#endif
	vertex_shader_file.close();
	
	GLuint vertex_shader;
	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, (const char **)&vertex_shader_source, NULL);
	delete[] vertex_shader_source;
	glCompileShader(vertex_shader);
	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &status);
	if(status == GL_FALSE)
	{
		cout<<"Vertex Shader did not compile\n";
		exit(0);
	}

	//compile fragment shader
	ifstream fragment_shader_file;
	int fragment_shader_length;
	fragment_shader_file.open("simple_shader.frag", ios::in);
	//go to end of the file to get total characters in the file
	fragment_shader_file.seekg(0, ios::end);
	fragment_shader_length = fragment_shader_file.tellg();
	fragment_shader_file.seekg(0, ios::beg);

	//allocated temporary character array for shader source
	char* fragment_shader_source = new char[fragment_shader_length + 1];//one extra character is for NULL
	fragment_shader_file.read(fragment_shader_source, fragment_shader_length);
	fragment_shader_source[vertex_shader_length] = '\0';
	fragment_shader_file.close();
	
	GLuint fragment_shader;
	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, (const char **)&fragment_shader_source, NULL);
	delete[] fragment_shader_source;
	glCompileShader(fragment_shader);
	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &status);
	if(status == GL_FALSE)
	{
		cout<<"Fragment Shader did not compile\n";
		exit(0);
	}

	//create program
	program_id = glCreateProgram();
	if(program_id == 0)
	{
		cout<<"Program not created\n";
		exit(0);
	}
	
	//attach shaders
	glAttachShader(program_id, vertex_shader);
	glAttachShader(program_id, fragment_shader);

	//link vertex and fragment shaders
	glLinkProgram(program_id);
	glGetProgramiv(program_id, GL_LINK_STATUS, &status);
	if(status == GL_FALSE)
	{
		cout<<"Linking Failed\n";
		exit(0);
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Hello Cube");
	glewInit();
	initialize();

	glutDisplayFunc(display);
	glutKeyboardFunc(key);
	glutMainLoop();
	return 0;
}
