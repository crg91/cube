attribute vec4 in_position;
attribute vec4 in_color;

varying vec4 v_color;

uniform mat4 transformation_matrix;

void main()
{
	//no modification on input position
	gl_Position	=	transformation_matrix*in_position;
	
	//pass color as varying to fragment shader
	v_color		=	in_color;
}
