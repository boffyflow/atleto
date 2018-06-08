function minuteString( num) {
	var  m = Math.floor( num / 60.0);
	var  s = num - m * 60;
	var  s_string;
	if( s < 10)
		s_string = '0' + s.toString();
	else 
		s_string = s.toString()
	var  result = m.toString() + ':' + s_string;
	return result;
}