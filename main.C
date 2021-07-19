//particleMain.cpp

#include "particleType.h"
#include "resonanceType.h"
#include "particle.h"
#include <iostream>
#include <cmath>
#include "TRandom.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TStyle.h"

using namespace std;


int main() 
{
 gStyle->SetOptFit(1111);

 TCanvas *c1=new TCanvas("c1","c1",65,75,700,700);
 c1->Divide(2,2);

 TH1F *hParticle=new TH1F("hParticle","Generated Particles",7,0,7);
 hParticle->SetFillColor(kRed);
 hParticle->SetLineColor(kBlack);
 hParticle->SetMarkerStyle(kFullCircle);
 hParticle->SetMarkerSize(0.8);
 hParticle->GetYaxis()->SetTitleOffset(1.2);
 hParticle->GetXaxis()->SetTitleSize(0.04);
 hParticle->GetYaxis()->SetTitleSize(0.04);
 hParticle->GetXaxis()->SetTitle("particle type");
 hParticle->GetYaxis()->SetTitle("Entries");

 TH1F *hTheta=new TH1F("hTheta","Polar Angle Distribution",1000,0,M_PI);
 hTheta->SetFillColor(kBlue);
 hTheta->SetLineColor(kBlack);
 hTheta->SetMarkerStyle(kFullCircle);
 hTheta->SetMarkerSize(0.8);
 hTheta->GetYaxis()->SetTitleOffset(1.2);
 hTheta->GetXaxis()->SetTitleSize(0.04);
 hTheta->GetYaxis()->SetTitleSize(0.04);
 hTheta->GetXaxis()->SetTitle("Polar angle (radiants)");
 hTheta->GetYaxis()->SetTitle("Entries");

 TH1F *hPhi= new TH1F("hPhi","Azimuth Angle Distribution",1000,0,2*M_PI);
 hPhi->SetFillColor(kGreen);
 hPhi->SetLineColor(kBlack);
 hPhi->SetMarkerStyle(kFullCircle);
 hPhi->SetMarkerSize(0.8);
 hPhi->GetYaxis()->SetTitleOffset(1.2);
 hPhi->GetXaxis()->SetTitleSize(0.04);
 hPhi->GetYaxis()->SetTitleSize(0.04);
 hPhi->GetXaxis()->SetTitle("Azimuth angle (radiants)");
 hPhi->GetYaxis()->SetTitle("Entries");

 TH1F *hP=new TH1F("hP","Momentum Distribution",1000,0,7);
 hP->SetFillColor(kYellow);
 hP->SetLineColor(kBlack);
 hP->SetMarkerStyle(kFullCircle);
 hP->SetMarkerSize(0.8);
 hP->GetYaxis()->SetTitleOffset(1.2);
 hP->GetXaxis()->SetTitleSize(0.04);
 hP->GetYaxis()->SetTitleSize(0.04);
 hP->GetXaxis()->SetTitle("Particle momentum (GeV)");
 hP->GetYaxis()->SetTitle("Entries");
 

 TCanvas *cA=new TCanvas("cA","cA",65,75,700,700);
 cA->Divide(2,2);

 TH1F *hPTr=new TH1F ("hPTr","Transverse Momentum Distribution",1000,0,5);
 hPTr->SetFillColor(kYellow);
 hPTr->SetLineColor(kBlack);
 hPTr->SetMarkerStyle(kFullCircle);
 hPTr->SetMarkerSize(0.8);
 hPTr->GetYaxis()->SetTitleOffset(1.2);
 hPTr->GetXaxis()->SetTitleSize(0.04);
 hPTr->GetYaxis()->SetTitleSize(0.04);
 hPTr->GetXaxis()->SetTitle("Transverse momentum (GeV)");
 hPTr->GetYaxis()->SetTitle("Entries");

 TH1F *hEnergy=new TH1F("hEnergy","Particle Energy Distribution",1000,0,6);
 hEnergy->SetFillColor(kBlue);
 hEnergy->SetLineColor(kBlack);
 hEnergy->SetMarkerStyle(kFullCircle);
 hEnergy->SetMarkerSize(0.8);
 hEnergy->GetYaxis()->SetTitleOffset(1.2);
 hEnergy->GetXaxis()->SetTitleSize(0.04);
 hEnergy->GetYaxis()->SetTitleSize(0.04);
 hEnergy->GetXaxis()->SetTitle("Particle Energy (GeV)");
 hEnergy->GetYaxis()->SetTitle("Entries");

 TH1F *hTotInvMass=new TH1F("hTotInvMass","Invariant Mass Distribution for all Particles",100,0.5,1.3);
 hTotInvMass->SetFillColor(kGreen);
 hTotInvMass->SetLineColor(kBlack);
 hTotInvMass->SetMarkerStyle(kFullCircle);
 hTotInvMass->SetMarkerSize(0.8);
 hTotInvMass->GetYaxis()->SetTitleOffset(1.2);
 hTotInvMass->GetXaxis()->SetTitleSize(0.04);
 hTotInvMass->GetYaxis()->SetTitleSize(0.04);
 hTotInvMass->GetXaxis()->SetTitle("Invariant mass (GeV/c^2)");
 hTotInvMass->GetYaxis()->SetTitle("Entries");

 
 TCanvas *cB=new TCanvas("cB","cB",65,75,700,700);
 cB->Divide(2,2);

 TH1F *hDisInvMass=new TH1F("hDisInvMass","Invariant Mass Distribution for Opposite Charge Particles",100,0.5,1.3);
 hDisInvMass->SetFillColor(kRed);
 hDisInvMass->SetLineColor(kBlack);
 hDisInvMass->SetMarkerStyle(kFullCircle);
 hDisInvMass->SetMarkerSize(0.8);
 hDisInvMass->GetYaxis()->SetTitleOffset(1.2);
 hDisInvMass->GetXaxis()->SetTitleSize(0.04);
 hDisInvMass->GetYaxis()->SetTitleSize(0.04);
 hDisInvMass->GetXaxis()->SetTitle("Invariant mass (GeV/c^2)");
 hDisInvMass->GetYaxis()->SetTitle("Entries");

 TH1F *hConInvMass=new TH1F("hConInvMass","Invariant Mass Distribution for Same Charge Particles",100,0.5,1.3);
 hConInvMass->SetFillColor(kBlue);
 hConInvMass->SetLineColor(kBlack);
 hConInvMass->SetMarkerStyle(kFullCircle);
 hConInvMass->SetMarkerSize(0.8);
 hConInvMass->GetYaxis()->SetTitleOffset(1.2);
 hConInvMass->GetXaxis()->SetTitleSize(0.04);
 hConInvMass->GetYaxis()->SetTitleSize(0.04);
 hConInvMass->GetXaxis()->SetTitle("Invariant mass (GeV/c^2)");
 hConInvMass->GetYaxis()->SetTitle("Entries");

 TH1F *hDisInvMassPiK=new TH1F("hDisInvMassPiK","Invariant Mass Distribution for K+/Pi- or K-/Pi+",100,0.5,1.3);
 hDisInvMassPiK->SetFillColor(kRed);
 hDisInvMassPiK->SetLineColor(kBlack);
 hDisInvMassPiK->SetMarkerStyle(kFullCircle);
 hDisInvMassPiK->SetMarkerSize(0.8);
 hDisInvMassPiK->GetYaxis()->SetTitleOffset(1.2);
 hDisInvMassPiK->GetXaxis()->SetTitleSize(0.04);
 hDisInvMassPiK->GetYaxis()->SetTitleSize(0.04);
 hDisInvMassPiK->GetXaxis()->SetTitle("Invariant mass (GeV/c^2)");
 hDisInvMassPiK->GetYaxis()->SetTitle("Entries");

 TH1F *hConInvMassPiK=new TH1F("hConInvMassPik","Invariant Mass Distribution for K+/Pi+ or K-/Pi-",100,0.5,1.3);
 hConInvMassPiK->SetFillColor(kBlue);
 hConInvMassPiK->SetLineColor(kBlack);
 hConInvMassPiK->SetMarkerStyle(kFullCircle);
 hConInvMassPiK->SetMarkerSize(0.8);
 hConInvMassPiK->GetYaxis()->SetTitleOffset(1.2);
 hConInvMassPiK->GetXaxis()->SetTitleSize(0.04);
 hConInvMassPiK->GetYaxis()->SetTitleSize(0.04);
 hConInvMassPiK->GetXaxis()->SetTitle("Invariant mass (GeV/c^2)");
 hConInvMassPiK->GetYaxis()->SetTitle("Entries");


 TCanvas *c2=new TCanvas("c2","c2",65,75,700,700);
 c2->Divide(3,1);

 TH1F *hInvMassK=new TH1F("hInvMassK","Invariant Mass of K* Decays",100,0.5,1.3);
 hInvMassK->SetFillColor(28);
 hInvMassK->SetLineColor(kBlack);
 hInvMassK->SetMarkerStyle(kFullCircle);
 hInvMassK->SetMarkerSize(0.8);
 hInvMassK->GetYaxis()->SetTitleOffset(1.2);
 hInvMassK->GetXaxis()->SetTitleSize(0.04);
 hInvMassK->GetYaxis()->SetTitleSize(0.04);
 hInvMassK->GetXaxis()->SetTitle("Invariant mass (GeV/c^2)");
 hInvMassK->GetYaxis()->SetTitle("Entries");

 TH1F *hSub1= new TH1F ("hSub1","Subtraction for K/Pi",100,0.5,1.3);
 hSub1->SetFillColor(kBlue);
 hSub1->SetLineColor(kBlack);
 hSub1->SetMarkerStyle(kFullCircle);
 hSub1->SetMarkerSize(0.8);
 hSub1->GetYaxis()->SetTitleOffset(1.2);
 hSub1->GetXaxis()->SetTitleSize(0.04);
 hSub1->GetYaxis()->SetTitleSize(0.04);
 hSub1->GetXaxis()->SetTitle("Invariant mass (GeV/c^2)");
 hSub1->GetYaxis()->SetTitle("Entries");
 
 TH1F *hSub2= new TH1F ("hSub2","Subtraction for all particles",100,0.5,1.3);
 hSub2->SetFillColor(kYellow);
 hSub2->SetLineColor(kBlack);
 hSub2->SetMarkerStyle(kFullCircle);
 hSub2->SetMarkerSize(0.8);
 hSub2->GetYaxis()->SetTitleOffset(1.2);
 hSub2->GetXaxis()->SetTitleSize(0.04);
 hSub2->GetYaxis()->SetTitleSize(0.04);
 hSub2->GetXaxis()->SetTitle("Invariant mass (GeV/c^2)");
 hSub2->GetYaxis()->SetTitle("Entries");


 Particle::AddParticleType("Pi+",0.13957,1,0);
 Particle::AddParticleType("Pi-",0.13957,-1,0);
 Particle::AddParticleType("K+",0.49367,1,0);
 Particle::AddParticleType("K-",0.49367,-1,0);
 Particle::AddParticleType("P+",0.93827,1,0);
 Particle::AddParticleType("P-",0.93827,-1,0);
 Particle::AddParticleType("K*",0.89166,0,0.050);

 Particle particle[120];
 double p,px,py,pz;
 double phi,theta;
 double x=0,y=0;
 int alarm=-1;
 int decay=0;
 gRandom->SetSeed();
 double invmassK;

 for(Int_t i=0;i<100000;i++) //10^5 EVENTS CYCLE
 {
   decay=0;

   for(Int_t j=0;j<100;j++) //SINGLE EVENT CYCLE
   {
    
    p=gRandom->Exp(1);
    hP->Fill(p);

    phi=gRandom->Uniform(0,2*M_PI);
    hPhi->Fill(phi);

    theta=gRandom->Uniform(0,M_PI);
    hTheta->Fill(theta);
   
    px=p*sin(theta)*cos(phi);
    py=p*sin(theta)*sin(phi);
    pz=p*cos(theta);
   
    hPTr->Fill(sqrt(px*px+py*py));
  
    particle[j].SetParticleP(px,py,pz);

    x=gRandom->Rndm();
    y=gRandom->Rndm();

    if(x<0.8) //GENERATION WITH PROPORTIONS
    {
     if(y<0.5)
     particle[j].SetParticleIndex("Pi+"),
     hParticle->Fill(0);
     else 
     particle[j].SetParticleIndex("Pi-"),
     hParticle->Fill(1);
    }
     else if(x<0.9)
    {
     if(y<0.5)
     particle[j].SetParticleIndex("K+"),
     hParticle->Fill(2);
     else 
     particle[j].SetParticleIndex("K-"),
     hParticle->Fill(3);
    }
    else if(x<0.99)
    {
     if(y<0.5)
     particle[j].SetParticleIndex("P+"),
     hParticle->Fill(4);
     else  
     particle[j].SetParticleIndex("P-"),
     hParticle->Fill(5);
    }
    else 
    {
     particle[j].SetParticleIndex("K*");
     hParticle->Fill(6);
     if(y<0.5) 
     {
      particle[100+2*decay].SetParticleIndex("Pi+");
      particle[101+2*decay].SetParticleIndex("K-");
     }
     else
     {
      particle[100+2*decay].SetParticleIndex("Pi-");
      particle[101+2*decay].SetParticleIndex("K+"); 
     }
     particle[j].Decay2body(particle[100+2*decay],particle[101+2*decay]);
     invmassK=particle[100+2*decay].GetInvariantMass(particle[101+2*decay]);
     hInvMassK->Fill(invmassK);
     decay++; 

    } //END OF GENERATION WITH PROPORTIONS

    hEnergy->Fill(particle[j].GetParticleEnergy());

   }//END OF EVENT
   

    for(int k=0;k<100+2*decay;k++) //INVARIANT MASS COMBINATIONS
    { 
     for(int l=1+k;l<100+2*decay;l++)
     {
      hTotInvMass->Fill(particle[k].GetInvariantMass(particle[l]));
      if( particle[k].GetParticleCharge()*particle[l].GetParticleCharge()<0 )
      {
        hDisInvMass->Fill(particle[k].GetInvariantMass(particle[l]));
        if( particle[k].GetParticleMass()+particle[l].GetParticleMass() == (0.49367 + 0.13957) )
        hDisInvMassPiK->Fill(particle[k].GetInvariantMass(particle[l]));
      }
      else if( particle[l].GetParticleCharge()*particle[k].GetParticleCharge()>0 )
      {
        hConInvMass->Fill(particle[k].GetInvariantMass(particle[l]));
        if( particle[k].GetParticleMass()+particle[l].GetParticleMass() == (0.49367 + 0.13957) )
        hConInvMassPiK-> Fill(particle[k].GetInvariantMass(particle[l]));
      }
     }
   } //END OF INVARIANT MASS COMBINATIONS
    
 } //END OF 10^5 EVENTS

 c1->cd(1);
 hParticle->Draw();
 for(Int_t i=0;i<7;i++)
 cout<<"Generated Particles content, bin "<<i+1<<": ("<<hParticle->GetBinContent(i+1)<<" +/- "<<hParticle->GetBinError(i+1)<<")"<<endl;

 c1->cd(2);
 hTheta->Fit("pol0"),cout<<endl;
 hTheta->Draw();
 
 c1->cd(3);
 hPhi->Fit("pol0"),cout<<endl;
 hPhi->Draw();

 c1->cd(4);
 hP->Fit("expo"),cout<<endl;
 hP->Draw();

 cA->cd(1);
 hPTr->Draw();

 cA->cd(2);
 hEnergy->Draw();

 cA->cd(3);
 hTotInvMass->Draw();

 cB->cd(1);
 hDisInvMass->Draw();

 cB->cd(2);
 hConInvMass->Draw();

 cB->cd(3);
 hDisInvMassPiK->Draw();

 cB->cd(4);
 hConInvMassPiK->Draw();

 c2->cd(1);
 hInvMassK->Fit("gaus");
 hInvMassK->Draw();

 c2->cd(2);
 hSub1->Add(hDisInvMassPiK,hConInvMassPiK,1,-1);
 hSub1->Fit("gaus","","",0.7,1.1),cout<<endl;
 hSub1->Draw();

 c2->cd(3);
 hSub2->Add(hDisInvMass,hConInvMass,1,-1);
 hSub2->Fit("gaus","","",0.7,1.1),cout<<endl;
 hSub2->Draw();

 } //END OF MAIN FUNCTION


