#
# Pre-condition: numbers does not repeated
my @my_list = (1, 2, 15, 21, 16);
my @sorted_my_list = 
my $max_value = @my_list[0];
my $min_value = @my_list[0];
my $len = @my_list;
print "1, 2, 15, 21, 16\n";
for(my $i = 1; $i < $len; ++$i){
	if(@my_list[$i] > $max_value){
		$max_value = @my_list[$i];
	}
	if(@my_list[$i] < $min_value){
		$min_value = @my_list[$i];
	}
}
print "Max value = $max_value\nMin value = $min_value\n";
my @my_copied_list = ($min_value..$max_value);
for(my $i = 0; $i < $len; ++$i){
	@my_copied_list[@my_list[$i]-1] = $max_value + 1;
}
for(my $i = 0, my $cp_len = @my_copied_list; $i < $cp_len; ++$i){
	if(@my_copied_list[$i] != ($max_value + 1)){
		push(@my_list, @my_copied_list[$i]);
	}
}
print "----------\n";
foreach $item (@my_list){
	print "$item ";
}
print "\n";
