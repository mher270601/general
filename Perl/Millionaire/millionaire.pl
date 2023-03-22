#
my $file = "millionaire.txt";
open(FH, '<', $file);
while(<FH>){
    $countOfLines = $.;
}
print `clear`;
my @questions;
my @answers;
my $_index = 0;
close(FH); 
open(FH, '<', $file);

while(<FH>){
    if($_index <= $countOfLines){
        if($.-1 == $_index){
            push (@questions, "$_");
            $_index += 5;
        }
        else{
            push (@answers, "$_");
        }
    }
}
close(FH);
$_index = 0;
$questionsLength = @questions;
open(FH, '<', $file);
my $currentIndx = 0;
my $questionIndx = 0;
my $coins = 0;
my $lifes = 2;
while(<FH>){
    if($_index < $countOfLines){
        print "Lifes: $lifes\nCoins: $coins\n\n\n";
        print "\t@questions[$questionIndx++]\n";
        $random1 = int(rand(4) + $currentIndx);
        if($random1 == $currentIndx) {$rightAnswer = "a";}
        do{
            $random2 = int(rand(4) + $currentIndx);
        }while($random2 == $random1);
        if($random2 == $currentIndx) {$rightAnswer = "b";}
        do{
            $random3 = int(rand(4) + $currentIndx);
        }while($random3 == $random1 or $random3 == $random2);
        if($random3 == $currentIndx) {$rightAnswer = "c";}
        do{
            $random4 = int(rand(4) + $currentIndx);
        }while($random4 == $random1 or $random4 == $random2 or $random4 == $random3);
        if($random4 == $currentIndx) {$rightAnswer = "d";}
        print "\n";
        print "a. @answers[$random1]\n";
        print "b. @answers[$random2]\n";
        print "c. @answers[$random3]\n";
        print "d. @answers[$random4]\n";
        $currentIndx += 4;
        $userAnswer = <STDIN>;
        chomp $userAnswer;
        if($userAnswer =~ /^[abcd]$/){
            if($userAnswer eq $rightAnswer){
                print "\n\tYou are right !\n";
                $coins += 1000;
            }
            else{
                print "\n\tWrong !, the right answer is $rightAnswer\n";
                $coins -= 700;
                $lifes -= 1;
            }
        }
        elsif($userAnswer eq "exit" or $userAnswer eq "e" or $userAnswer eq "quit"){
            exit;
        }
        else{
            print"\n\tIncorrect answer !\n";
            exit;
        }
        if($lifes == 0){
            print "\n\tYou lose the game !\n";
            exit;
        }
        sleep(2);
        print `clear`;
        $_index += 5;
    }
}
print "\nYOU WIN !\n";
print "TOTAL COINS $coins\n";
