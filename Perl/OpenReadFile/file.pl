#
print("Please enter the file name: ");
my $file_name = <STDIN>;
chomp $file_name;
if(-e $file_name){
	open(INFO, $file_name) or die "Could not open file.";
	foreach $line (<INFO>){
		print "$line\n";
	}
}else{
	print("File is not exsists\n");
}
