varying vec4 v_color;

void main()
{
	//output varying input color to renderbuffer
	gl_FragColor = v_color;
}
