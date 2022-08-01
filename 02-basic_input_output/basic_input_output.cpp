
void basic_input_output(unsigned char input,
						unsigned char *output)
{
#pragma HLS INTERFACE ap_none port=output
#pragma HLS INTERFACE ap_none port=input
#pragma HLS INTERFACE ap_ctrl_none port=return

	*output = input;
}
