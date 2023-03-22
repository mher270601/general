#
my $fileName = "netlist.txt";
print("Input technology(5, 7, 14, 32, 90 (nm)): ");
$technology = <STDIN>;
chomp $technology;
if($technology =~ /^[57]$/ or $technology eq '14' or $technology eq '32' or $technology eq '90'){
    open(FH, '>>', $fileName) or die "Could not open file\n";
    do{
        print("Input (R, L, C, m): ");
        $input = <STDIN>;
        chomp $input;
        if($input =~ /^[RLCm]$/){
            print "Input name: ";
            my $name = <STDIN>;
            chomp $name;
            if($input =~ /^[RLC]$/){
                print "Input Pin1: ";
                my $pin1 = <STDIN>;
                chomp $pin1;
                print "Input Pin2: ";
                my $pin2 = <STDIN>;
                chomp $pin2;
                print "Input value(def = 1K): ";
                my $value = <STDIN>;
                chomp $value;
                if($value eq ''){
                    $value = '1K';
                }
                if($value !~ /\d+[fpnumKM]$/ and $value =~ /\d+/){
                    $value = $value . "K";
                }
                print FH "$input: $name $pin1 $pin2 $value\n";
            }
            elsif($input eq 'm'){
                print "Input D: ";
                my $drain = <STDIN>;
                chomp $drain;
                print "Input G: ";
                my $gate = <STDIN>;
                chomp $gate;
                print "Input S: ";
                my $sorce = <STDIN>;
                chomp $sorce;
                print "Input B: ";
                my $bulk = <STDIN>;
                chomp $bulk;
                print "Input W: ";
                my $widht = <STDIN>;
                chomp $widht;
                print FH "m: $name $drain $gate $sorce $bulk $width 0.5u";
            }
        }
    }while($input ne 'exit');
    close FH;
}
open(FH, '<', $fileName);
while(<FH>){
    print $_;
}
close(FH);
