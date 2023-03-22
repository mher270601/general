#

my @my_list = (1, 1, 2, 1, 3, 2, 3); # Sum = 13
my $max_value = @my_list[0];
my $len = @my_list;
my %hash;
my %hash_list;
for(my $i = 1; $i < $len; ++$i){
	if(@my_list[$i] > $max_value){
		$max_value = @my_list[$i];
	}
	push(@{ $hash_list{@my_list[$i]} }, 1);
}
my @values;
foreach $string (keys %hash_list){
	push(@values, $string);
	push(@{ $hash{$string} }, 1);
	#if(@{$hash_list{$string}} == 'true'){
	#	@{$hash_list{$string}} == 'false';
	#	print "false\n";
	#}elsif(@{$hash_list{$string}} == 'false'){
	#	@{$hash_list{$string}} == 'true';
	#	print "true\n";
	#}
	#print "$string: @{$hash_list{$string}}\n";
}
undef %hash_list;
my $values_len = @values;
for(my $i = 0; $i < $len; ++$i){
	#print "@{$hash{@my_list[$i]}}\n";
	my $current_value = %hash{@my_list[$i]};
	if(@{$hash{@my_list[$i]}} == 1){

		print "@{$hash{@my_list[$i]}} converted to 0\n";	
		@{$hash{@my_list[$i]}} = 0;
		$hash{@my_list[$i]} = 0;
		print "@{$hash{@my_list[$i]}}\n";
	}
	elsif(@{$hash{@my_list[$i]}} == 0){
		print "@{$hash{@my_list[$i]}} converted to 1\n";
		@{$hash{@my_list[$i]}} = 1;
		$hash{@my_list[$i]} = 1;
	}
}
print "==========\n";
foreach $item (keys %hash){
	#if(%hash{$item} == 0){
		print @hash{$item};
		print "\n";
	#}
	#print "\n";
}
print "==========\n";
print "--------\n";
foreach $string (keys %hash){
	if($hash{$string} == 1){
		print "Value = $string\n";
	}
	print "$string: @{$hash{$string}}\n";
	#push(@values, $string);
	#if(@{$hash_list{$string}} == 'true'){
	#	@{$hash_list{$string}} == 'false';
	#	print "false\n";
	#}elsif(@{$hash_list{$string}} == 'false'){
	#	@{$hash_list{$string}} == 'true';
	#	print "true\n";
	#}
	#print "$string: @{$hash_list{$string}}\n";
}
print "--------\n";
#for(my $i = 0; $i < $values_len; ++$i){
#	print "@values[$i]\n";
#}
#print "\n$max_value\n";
my @second_list;
# 7, 5, 3, 8, 14, 14, 5, 3, 8, 5, 7
# Data struture (interface, memory impact)
# Reentrant, Thread-safe, Memory leaks
# Red-Black trees
