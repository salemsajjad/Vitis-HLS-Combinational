void simple_circuit(
		bool a,
		bool b,
		bool c,
		bool *d)
{
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE ap_none port=a
#pragma HLS INTERFACE ap_none port=b
#pragma HLS INTERFACE ap_none port=c
#pragma HLS INTERFACE ap_none port=d


	*d = (a && b) || !c;
}
