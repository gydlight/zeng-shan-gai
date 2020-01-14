const readline = require('readline');

async function input(msg){

	return await new Promise( (resolve,reject)=>{
		const rl = readline.createInterface({
  			input: process.stdin,
  			output: process.stdout
		});

		rl.question( msg, (answer) => {
 			resolve(answer);
			rl.close();
		});
				
	
	
	
	} )

}
(async()=>{
	var s1=await input('你想要什么图形?\n1:三角形\n2:梯形\n3:菱形\n4:正方形\n');
	console.log(s1);
	var s2=await input('请输入高度(10以上的偶数)\n');
	console.log(s2);
	var s3=await input('你想要什么图形?\n1:实心\n2:空心');
	run(s1,s2,s3);

})()	;



function run (s1,s2,s3){
var z1='';
var z2='';
var z3='';
var z4='';
var y=Number(s2) ;
var x=2*y-1;
var n=y-1;
var m=(x-1)/2;
var s=parseInt(x/3);


switch (s1){
	case "1":if(s3==1){

		for(var i=0;i<y;i++){
        		for(var j=0;j<x;j++){
                		if(i>=Math.abs(n/m*(-1)*j+n) || i==n){
                        		z1+=' *';
                		}else{z1+='  '};
        		}
        	z1+='\n'
		}}else{
		
		for(var i=0;i<y;i++){
                        for(var j=0;j<x;j++){
                                if(i<=Math.abs(n/m*(-1)*j+n) || i==n){
                                        z1+=' *';
                                }else{z1+='  '};
                        }
                z1+='\n'

		
		}};
		console.log(z1);
		break;
	case "2":if(s3==1){


		for(var i=0;i<y;i++){
        		for(var j=0;j<x;j++){
                		if(i>=Math.abs(n/m*(-1)*j+n) || i==n ||( i==y/2 && i>=Math.abs(n/m*(-1)*j+n) )){
                     			if(i>=y/2){ z2+=' *';}else{z2+='  ' }
                		}else{z2+='  '};
        		}
        	z2+='\n'
		}}else{
		
		for(var i=0;i<y;i++){
                        for(var j=0;j<x;j++){
                                if(i<=Math.abs(n/m*(-1)*j+n) || i==n || i<=y/2){
                        		z2+=' *';
                                }else{z2+='  '};
                        }
                z2+='\n'
		
		}};
		console.log(z2);

		break;
	case "3":if(s3==1){


		for(var i=0;i<2*y-1;i++){
        		for(var j=0;j<x;j++){
                		if(i>=Math.abs(n/m*(-1)*j+n) && i<=Math.abs(n/m*(-1)*j+n)*(-1)+2*y-2 ){
                        		z3+=' *';
                		}else{z3+='  '};
        		}
        	z3+='\n'
		}}else{
		for(var i=0;i<2*y-1;i++){
                        for(var j=0;j<x;j++){
                                if(i<=Math.abs(n/m*(-1)*j+n) || i>=Math.abs(n/m*(-1)*j+n)*(-1)+2*y-2 ){
                                        z3+=' *';
                                }else{z3+='  '};
                        }
                z3+='\n'
		
		
		}}
		console.log(z3);
		
		
		
		
		
		
		break;
	case "4":console.log('回字没有实心');

		for(var i=0;i<x;i++){
        		for(var j=0;j<x;j++){
                		if(i==0||i==x-1||j==0||j==x-1){
                        		z4+=' *';
                		}else if((i==s||i==2*s) &&(j<=2*s && j>=s) ){
                        		z4+=' *';
                		}else if((j==s||j==2*s) &&(i<=2*s && i>=s)){
                         		z4+=' *';
                		}else{z4+='  '};
        		}
        	z4+='\n'
}
		console.log(z4);
		break;

default:
	console.log('输入错误');

	(async()=>{
        var s1=await input('你想要什么图形?\n1:三角形\n2:梯形\n3:菱形\n4:正方形\n');
        console.log(s1);
        var s2=await input('请输入高度(10以上的偶数)\n');
        console.log(s2);
        var s3=await input('你想要什么图形?\n1:实心\n2:空心');
        run(s1,s2,s3);

})()    ;


}



}















