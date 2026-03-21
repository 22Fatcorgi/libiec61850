<?xml version="1.0" encoding="UTF-8"?>
<SCL xmlns="http://www.iec.ch/61850/2003/SCL" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" version="2007" revision="B">
  <Header id="" revision="1" version="0" toolID="INFO TECH ICD Editor" nameStructure="IEDName">
 </Header>
  <Communication>
    <SubNetwork name="S1">
      <ConnectedAP iedName="projectDER" apName="P1">
        <Address>
          <P type="IP">127.0.0.1</P>
          <P type="IP-SUBNET">255.255.255.0</P>
          <P type="OSI-AP-Title">1,3,9999,23</P>
          <P type="OSI-AE-Qualifier">23</P>
          <P type="OSI-PSEL">00000001</P>
          <P type="OSI-SSEL">0001</P>
          <P type="OSI-TSEL">0001</P>
        </Address>
      </ConnectedAP>
      <ConnectedAP iedName="Client1" apName="P1">
        <Address>
          <P type="IP">192.168.50.187</P>
	  <P type="IP-SUBNET">255.255.255.0</P>
        </Address>
      </ConnectedAP>
    </SubNetwork>
  </Communication>
  <IED name="projectDER" configVersion="1.0" type="" manufacturer="" desc="">
    <Services nameLength="64">
      <DynAssociation max="0"/>
      <SettingGroups/>
      <GetDirectory/>
      <GetDataObjectDefinition/>
      <DataObjectDirectory/>
      <GetDataSetValue/>
      <DataSetDirectory/>
      <ConfDataSet max="0"/>
      <DynDataSet max="0"/>
      <ReadWrite/>
      <ConfReportControl max="0"/>
      <GetCBValues/>
      <ReportSettings cbName="Dyn" dataSet="Dyn" rptID="Dyn" optFleds="Dyn" bufTime="Dyn" trgOps="Dyn" intgPd="Dyn" resvTms="true" owner="true"/>
      <GSESettings/>
      <ConfLNs/>
      <GOOSE max="0"/>
      <FileHandling/>
    </Services>
    <AccessPoint name="P1">
      <Server>
        <Authentication none="true"/>
        <LDevice inst="DER3">
          <LN0 lnClass="LLN0" inst="" lnType="LLN0_2">
            <DataSet name="ESS">
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DSTO" doName="ChaWhTotRs" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DSTO" doName="DschWhTotRs" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DSTO" doName="AutoConn" fc="SP"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DSTO" doName="CeaEgzCtl" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DSTO" doName="EmgMod" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DSTO" doName="AuthDscon" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DSTO" doName="TestEna" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DSTO" doName="Test" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DSTO" doName="CmdBlk" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DSTO" doName="LocSta" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DSTO" doName="ClcStr" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DSTO" doName="EqSto" fc="DC"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DSTO" doName="EqSto" fc="SP"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DSTO" doName="ChaWMax" fc="DC"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DSTO" doName="ChaWMax" fc="SP"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DSTO" doName="PhsConnTyp" fc="DC"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DSTO" doName="PhsConnTyp" fc="SP"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DSTO" doName="DERTyp" fc="DC"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DSTO" doName="DERTyp" fc="SP"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="SBAT" doName="Beh" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="SBAT" doName="ExtVol" fc="MX"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="SBAT" doName="IntnVol" fc="MX"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="SBAT" doName="CelVolRs" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="SBAT" doName="ClcStr" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DBAT" doName="Beh" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DBAT" doName="Amp" fc="MX"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DBAT" doName="Watt" fc="MX"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DBAT" doName="CmdBlk" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DBAT" doName="LocSta" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DBAT" doName="ClcStr" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DBAT" doName="BatTyp" fc="DC"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DBAT" doName="BatTyp" fc="SP"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="CSWI" doName="Pos" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="CSWI" doName="PosA" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="CSWI" doName="PosB" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="CSWI" doName="PosC" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="XSWI" doName="Pos" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="XSWI" doName="BlkOpn" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="XSWI" doName="BlkCls" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="XSWI" doName="ChaMotEna" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="XSWI" doName="SwTyp" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="XSWI" doName="SwOpCap" fc="ST"/>
            </DataSet>
            <DataSet name="Measure">
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DBAT" doName="Amp" fc="MX"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="DBAT" doName="Watt" fc="MX"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="MMXU" doName="A" fc="MX"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="MMXU" doName="W" fc="MX"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="MMXU" doName="VAr" fc="MX"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="MMXU" doName="VA" fc="MX"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="MMXU" doName="PPV" fc="MX"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="MMXU" doName="PhV" fc="MX"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="SBAT" doName="ExtVol" fc="MX"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="SBAT" doName="IntnVol" fc="MX"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="MMDC" doName="Watt" fc="MX"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="MMDC" doName="Amp" fc="MX"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="MMDC" doName="Vol" fc="MX"/>
            </DataSet>
            <DataSet name="PCS">
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="XCBR" doName="Loc" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="XCBR" doName="Pos" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="XCBR" doName="OpCnt" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="XCBR" doName="BlkOpn" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="XCBR" doName="BlkCls" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="XCBR" doName="ChaMotEna" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="XCBR" doName="CBOpCap" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="CSWI" doName="Pos" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="CSWI" doName="PosA" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="CSWI" doName="PosB" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="CSWI" doName="PosC" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="MMXU" doName="PPV" fc="MX"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="MMXU" doName="PhV" fc="MX"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="MMXU" doName="A" fc="MX"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="MMXU" doName="W" fc="MX"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="MMXU" doName="VAr" fc="MX"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="MMXU" doName="VA" fc="MX"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="MMDC" doName="Watt" fc="MX"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="MMDC" doName="Amp" fc="MX"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="MMDC" doName="Vol" fc="MX"/>
            </DataSet>
            <DataSet name="Control">
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="XCBR" doName="Pos" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="XCBR" doName="BlkOpn" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="XCBR" doName="BlkCls" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="XCBR" doName="ChaMotEna" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="CSWI" doName="Pos" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="CSWI" doName="PosA" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="CSWI" doName="PosB" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="CSWI" doName="PosC" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="XSWI" doName="Pos" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="XSWI" doName="BlkOpn" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="XSWI" doName="ChaMotEna" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="XSWI" doName="BlkCls" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="GGIO" doName="SPCSO1" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="GGIO" doName="DPCSO1" fc="ST"/>
            </DataSet>
            <DataSet name="A1234567890123456789012345678901">
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="GGIO" doName="SPCSO1" fc="CF"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="GGIO" doName="SPCSO1" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="MMXU" doName="Hz" fc="MX"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="MMXU" doName="Hz" daName="mag.f" fc="MX"/>
            </DataSet>
            <DataSet name="Test">
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="GGIO" doName="SPCSO1" fc="CF"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="GGIO" doName="SPCSO1" fc="ST"/>
              <FCDA ldInst="DER3" prefix="" lnInst="1" lnClass="MMXU" doName="Hz" fc="MX"/>
            </DataSet>
            <ReportControl buffered="false" name="URCB" datSet="ESS" bufTime="1000" intgPd="0" confRev="1" indexed="false">
              <TrgOps dchg="true" qchg="true" dupd="true" period="true" gi="true"/>
              <OptFields seqNum="true" timeStamp="true" dataSet="true" reasonCode="true" dataRef="true" configRef="true" bufOvfl="false"/>
              <RptEnabled max="1"/>
            </ReportControl>
            <ReportControl buffered="true" name="BRCB" datSet="ESS" bufTime="1000" intgPd="0" confRev="1" indexed="false">
              <TrgOps dchg="true" qchg="true" dupd="true" period="true" gi="true"/>
              <OptFields seqNum="true" timeStamp="true" dataSet="true" reasonCode="true" dataRef="true" entryID="false" configRef="true" bufOvfl="false"/>
              <RptEnabled max="1"/>
            </ReportControl>
            <ReportControl buffered="true" name="B1234567890123456789012345678901" bufTime="0" intgPd="30000" confRev="1" rptID="C12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678" indexed="true" datSet="A1234567890123456789012345678901">
              <TrgOps dchg="true" qchg="false" dupd="false" period="true" gi="true"/>
              <OptFields seqNum="true" timeStamp="true" dataSet="true" reasonCode="true" dataRef="true" entryID="true" configRef="true" bufOvfl="true"/>
              <RptEnabled max="1"/>
            </ReportControl>
            <ReportControl buffered="true" name="Test" datSet="Test" bufTime="1000" intgPd="0" confRev="1" indexed="true">
              <TrgOps dchg="true" qchg="true" dupd="true" period="true" gi="true"/>
              <OptFields seqNum="true" timeStamp="true" dataSet="true" reasonCode="true" dataRef="true" entryID="true" configRef="true" bufOvfl="true"/>
              <RptEnabled max="1">
                <ClientLN iedName="Client1" ldInst="LD0" lnClass="IHMI" lnInst="1"/>
              </RptEnabled>
            </ReportControl>
            <DOI name="NamPlt">
              <DAI name="ldNs">
                <Val>IEC 61850-7-4:2007B</Val>
              </DAI>
            </DOI>
            <DOI name="Beh">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
            </DOI>
            <DOI name="Mod">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
          </LN0>
          <LN lnClass="LPHD" inst="1" lnType="LPHD_2"/>
          <LN lnClass="MMXU" inst="1" lnType="MMXU_2"/>
          <LN lnClass="ZBAT" inst="1" lnType="ZBAT_2">
            <DOI name="Beh">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
            </DOI>
            <DOI name="BatTest">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="Mod">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
            </DOI>
            <DOI name="BatSt">
              <DAI name="dataNs">
                <Val>private_do_zbat_batst</Val>
              </DAI>
            </DOI>
            <DOI name="BatTyp">
              <DAI name="dataNs">
                <Val>private_do_zbat_battyp</Val>
              </DAI>
            </DOI>
          </LN>
          <LN lnClass="ZBTC" inst="1" lnType="ZBTC_2">
            <DOI name="Beh">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
            </DOI>
            <DOI name="BatChaMod">
              <DAI name="dataNs">
                <Val>private_do_zbtc_batchamod</Val>
              </DAI>
            </DOI>
          </LN>
          <LN lnClass="GGIO" inst="1" lnType="GGIO_2">
            <DOI name="Beh">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
            </DOI>
            <DOI name="SPCSO1">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="DPCSO1">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="ISCSO1">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="OpCntRs">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="Mod">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
          </LN>
          <LN lnClass="PTOV" inst="1" lnType="PTOV_2">
            <DOI name="Beh">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
            </DOI>
          </LN>
          <LN lnClass="PTOC" inst="1" lnType="PTOC_1">
            <DOI name="Beh">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
            </DOI>
          </LN>
          <LN lnClass="DCCT" inst="1" lnType="DCCT_2">
            <DOI name="NamPlt">
              <DAI name="lnNs">
                <Val>IEC 61850-7-420:2019</Val>
              </DAI>
            </DOI>
            <DOI name="Beh">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
            </DOI>
            <DOI name="Mod">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
            </DOI>
          </LN>
          <LN lnClass="CSWI" inst="1" lnType="CSWI_1">
            <DOI name="Beh">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
            </DOI>
            <DOI name="Mod">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
            </DOI>
            <DOI name="Pos">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="PosA">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="PosB">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="PosC">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="OpCntRs">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="LocSta">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
          </LN>
          <LN lnClass="XCBR" inst="1" lnType="XCBR_1">
            <DOI name="Beh">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
            </DOI>
            <DOI name="LocSta">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="Pos">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="BlkOpn">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="BlkCls">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="ChaMotEna">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="Mod">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
            </DOI>
          </LN>
          <LN lnClass="XSWI" inst="1" lnType="XSWI_1">
            <DOI name="LocSta">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="Pos">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="BlkOpn">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="BlkCls">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="ChaMotEna">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
          </LN>
          <LN lnClass="DBAT" inst="1" lnType="DBAT_2">
            <DOI name="NamPlt">
              <DAI name="lnNs">
                <Val>IEC 61850-7-420:2019</Val>
              </DAI>
            </DOI>
            <DOI name="Beh">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
            </DOI>
            <DOI name="Mod">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="ClcStr">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="LocSta">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="CmdBlk">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="OpCntRs">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
          </LN>
          <LN lnClass="DSTO" inst="1" lnType="DSTO_2">
            <DOI name="NamPlt">
              <DAI name="lnNs">
                <Val>IEC 61850-7-420:2019</Val>
              </DAI>
            </DOI>
            <DOI name="Beh">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
            </DOI>
            <DOI name="Mod">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="ClcStr">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="LocSta">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="CmdBlk">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="OpCntRs">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="AuthConn">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="DEROpStCtl">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="CeaEgzCtl">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="WSpt">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="VArSpt">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="EmgMod">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="AuthDscon">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="TestEna">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="Test">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="ChaWhTotRs">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="DschWhTotRs">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
          </LN>
          <LN lnClass="SBAT" inst="1" lnType="SBAT_1">
            <DOI name="NamPlt">
              <DAI name="lnNs">
                <Val>IEC 61850-7-420:2019</Val>
              </DAI>
            </DOI>
            <DOI name="Beh">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
            </DOI>
            <DOI name="Mod">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
            </DOI>
            <DOI name="ClcStr">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="OpCntRs">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="CelVolRs">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
          </LN>
          <LN lnClass="DECP" inst="1" lnType="DECP_2">
            <DOI name="NamPlt">
              <DAI name="lnNs">
                <Val>IEC 61850-7-420:2019</Val>
              </DAI>
            </DOI>
            <DOI name="Beh">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
            </DOI>
            <DOI name="Mod">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="ClcStr">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
          </LN>
          <LN lnClass="DPCC" inst="1" lnType="DPCC_1">
            <DOI name="NamPlt">
              <DAI name="lnNs">
                <Val>IEC 61850-7-420:2019</Val>
              </DAI>
            </DOI>
            <DOI name="Beh">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
            </DOI>
            <DOI name="Mod">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="ClcStr">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
          </LN>
          <LN lnClass="DVER" inst="1" lnType="DVER_1">
            <DOI name="NamPlt">
              <DAI name="lnNs">
                <Val>IEC 61850-7-420:2019</Val>
              </DAI>
            </DOI>
            <DOI name="Beh">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
            </DOI>
            <DOI name="Mod">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
            <DOI name="ClcStr">
              <DAI name="ctlModel">
                <Val>direct-with-normal-security</Val>
              </DAI>
            </DOI>
          </LN>
          <LN lnClass="MMDC" inst="1" lnType="MMDC_1">
            <DOI name="Beh">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
            </DOI>
            <DOI name="Mod">
              <DAI name="stVal">
                <Val>on</Val>
              </DAI>
            </DOI>
          </LN>
        </LDevice>
      </Server>
    </AccessPoint>
  </IED>

  <DataTypeTemplates>
    <LNodeType id="CSWI_1" lnClass="CSWI">
      <DO name="NamPlt" type="LPL_2"/>
      <DO name="Beh" type="ENS_1"/>
      <DO name="Mod" type="ENC_4"/>
      <DO name="LocKey" type="SPS_1"/>
      <DO name="Loc" type="SPS_1"/>
      <DO name="OpOpn" type="ACT_1"/>
      <DO name="SelOpn" type="SPS_1"/>
      <DO name="OpCls" type="ACT_1"/>
      <DO name="SelCls" type="SPS_1"/>
      <DO name="OpCntRs" type="INC_1"/>
      <DO name="LocSta" type="SPC_3"/>
      <DO name="Pos" type="DPC_1"/>
      <DO name="PosA" type="DPC_1"/>
      <DO name="PosB" type="DPC_1"/>
      <DO name="PosC" type="DPC_1"/>
    </LNodeType>
    <LNodeType id="DBAT_2" lnClass="DBAT">
      <DO name="NamPlt" type="LPL_3"/>
      <DO name="Beh" type="ENS_1"/>
      <DO name="Health" type="ENS_2"/>
      <DO name="Mir" type="SPS_1"/>
      <DO name="Mod" type="ENC_2"/>
      <DO name="ClcExp" type="SPS_1"/>
      <DO name="ClcNxtTmms" type="INS_1"/>
      <DO name="ClcStr" type="SPC_3"/>
      <DO name="ClcMth" type="ENG_1"/>
      <DO name="ClcSrc" type="ORG_2"/>
      <DO name="Blk" type="SPS_1"/>
      <DO name="Loc" type="SPS_1"/>
      <DO name="LocKey" type="SPS_1"/>
      <DO name="LocSta" type="SPC_3"/>
      <DO name="CmdBlk" type="SPC_3"/>
      <DO name="OpCntRs" type="INC_1"/>
      <DO name="EEName" type="DPL_1"/>
      <DO name="EEHealth" type="ENS_2"/>
      <DO name="OpTmh" type="INS_1"/>
      <DO name="SocPro" type="SPS_1"/>
      <DO name="ChaSt" type="SPS_1"/>
      <DO name="DschSt" type="SPS_1"/>
      <DO name="TestRsl" type="SPS_1"/>
      <DO name="TestAddRsl" type="ENS_7"/>
      <DO name="DCSwCls" type="SPS_1"/>
      <DO name="Amp" type="MV_1"/>
      <DO name="Watt" type="MV_1"/>
      <DO name="ChaAmpLim" type="MV_1"/>
      <DO name="EffAhr" type="MV_1"/>
      <DO name="ChaVolLim" type="MV_1"/>
      <DO name="DschAmpLim" type="MV_1"/>
      <DO name="CelStrgCnt" type="MV_1"/>
      <DO name="AvlChaAhr" type="MV_1"/>
      <DO name="AvlDschAhr" type="MV_1"/>
      <DO name="ChaAhrTot" type="MV_1"/>
      <DO name="DschAhrTot" type="MV_1"/>
      <DO name="SocEffAhrPct" type="MV_1"/>
      <DO name="SocDvPct" type="MV_1"/>
      <DO name="VolChgRte" type="MV_1"/>
      <DO name="DschVolLim" type="MV_1"/>
      <DO name="CycSocRngPct" type="MV_1"/>
      <DO name="CycAmpAv" type="MV_1"/>
      <DO name="BatTyp" type="ENG_4"/>
      <DO name="ChaAmpMaxRtg" type="ASG_1"/>
      <DO name="AhrRtg" type="ASG_1"/>
      <DO name="EffAhrRtg" type="ASG_1"/>
      <DO name="AhrMinRtg" type="ASG_1"/>
      <DO name="ChaVolMaxRtg" type="ASG_1"/>
      <DO name="DschAmpMxRtg" type="ASG_1"/>
      <DO name="ExtVolMaxRtg" type="ASG_1"/>
      <DO name="ExtVolNom" type="ASG_1"/>
      <DO name="IntnVolNom" type="ASG_1"/>
      <DO name="IntnVNom" type="ASG_1"/>
      <DO name="SelfDschWRte" type="ASG_1"/>
      <DO name="CelParCnt" type="ING_1"/>
      <DO name="CelSerCnt" type="ING_1"/>
      <DO name="DschWattCrv" type="CSG_4"/>
      <DO name="DschWattTm" type="CSG_6"/>
    </LNodeType>
    <LNodeType id="DCCT_2" lnClass="DCCT">
      <DO name="Mod" type="ENC_4"/>
      <DO name="Beh" type="ENS_1"/>
      <DO name="Health" type="ENS_2"/>
      <DO name="NamPlt" type="LPL_3"/>
      <DO name="Ccy" type="CUG_1"/>
      <DO name="OpCost" type="CUG_1"/>
      <DO name="OpWCost" type="CUG_2"/>
      <DO name="StrCost" type="CUG_1"/>
      <DO name="StopCost" type="CUG_1"/>
      <DO name="RampCost" type="CUG_1"/>
      <DO name="Blk" type="SPS_1"/>
      <DO name="BlkRef1" type="ORG_1"/>
      <DO name="CRteCost" type="CSG_4"/>
      <DO name="ClcExp" type="SPS_1"/>
      <DO name="ClcIntvPer" type="ING_1"/>
      <DO name="ClcIntvTyp" type="ENG_3"/>
      <DO name="ClcMod" type="ENG_2"/>
      <DO name="ClcMth" type="ENG_1"/>
      <DO name="ClcNxtTmms" type="INS_1"/>
      <DO name="ClcRfPer" type="ING_1"/>
      <DO name="ClcRfTyp" type="ENG_3"/>
      <DO name="ClcSrc" type="ORG_1"/>
      <DO name="ClcStr" type="SPC_4"/>
      <DO name="HeatRteCost" type="CSG_10"/>
      <DO name="InRef1" type="ORG_1"/>
      <DO name="InSyn" type="ORG_1"/>
      <DO name="Mir" type="SPS_1"/>
      <DO name="NumSubIntv" type="ING_1"/>
      <DO name="OpWhCost" type="ASG_5"/>
    </LNodeType>
    <LNodeType id="DECP_2" lnClass="DECP">
      <DO name="NamPlt" type="LPL_3"/>
      <DO name="Beh" type="ENS_1"/>
      <DO name="Health" type="ENS_2"/>
      <DO name="Mir" type="SPS_1"/>
      <DO name="Mod" type="ENC_2"/>
      <DO name="InRef1" type="ORG_2"/>
      <DO name="ClcExp" type="SPS_1"/>
      <DO name="ClcNxtTmms" type="INS_1"/>
      <DO name="ClcStr" type="SPC_3"/>
      <DO name="ClcMth" type="ENG_1"/>
      <DO name="ClcMod" type="ENG_2"/>
      <DO name="ClcIntvTyp" type="ENG_3"/>
      <DO name="ClcIntvPer" type="ING_1"/>
      <DO name="NumSubIntv" type="ING_1"/>
      <DO name="ClcRfTyp" type="ENG_3"/>
      <DO name="ClcRfPer" type="ING_1"/>
      <DO name="ClcSrc" type="ORG_3"/>
      <DO name="InSyn" type="ORG_2"/>
      <DO name="Blk" type="SPS_1"/>
      <DO name="BlkRef1" type="ORG_2"/>
      <DO name="ElcStCtlRef1" type="ORG_2"/>
      <DO name="ElcRefId" type="VSG_1"/>
      <DO name="ElcMsRef1" type="ORG_2"/>
      <DO name="EcpIsldSt" type="ENS_9"/>
      <DO name="PhsConnTyp" type="ENG_10"/>
      <DO name="GndSys" type="ENG_15"/>
      <DO name="VRef" type="ASG_3"/>
      <DO name="VRefPct" type="ASG_1"/>
      <DO name="VArRtg" type="ASG_1"/>
      <DO name="VARtg" type="ASG_1"/>
      <DO name="WRtg" type="ASG_1"/>
      <DO name="VRtg" type="ASG_1"/>
      <DO name="HzNom" type="ASG_1"/>
      <DO name="VMax" type="ASG_1"/>
      <DO name="VMin" type="ASG_1"/>
      <DO name="DERMsIncl" type="SPG_1"/>
      <DO name="RefFrm" type="SPG_1"/>
      <DO name="EcpIsldAuto" type="SPG_1"/>
    </LNodeType>
    <LNodeType id="DPCC_1" lnClass="DPCC">
      <DO name="NamPlt" type="LPL_3"/>
      <DO name="Beh" type="ENS_1"/>
      <DO name="Health" type="ENS_2"/>
      <DO name="Mir" type="SPS_1"/>
      <DO name="Mod" type="ENC_2"/>
      <DO name="InRef1" type="ORG_2"/>
      <DO name="ClcExp" type="SPS_1"/>
      <DO name="ClcNxtTmms" type="INS_1"/>
      <DO name="ClcStr" type="SPC_3"/>
      <DO name="ClcMth" type="ENG_1"/>
      <DO name="ClcMod" type="ENG_2"/>
      <DO name="ClcIntvTyp" type="ENG_3"/>
      <DO name="ClcIntvPer" type="ING_1"/>
      <DO name="NumSubIntv" type="ING_1"/>
      <DO name="ClcRfTyp" type="ENG_3"/>
      <DO name="ClcRfPer" type="ING_1"/>
      <DO name="ClcSrc" type="ORG_3"/>
      <DO name="InSyn" type="ORG_2"/>
      <DO name="Blk" type="SPS_1"/>
      <DO name="BlkRef1" type="ORG_2"/>
      <DO name="ElcStCtlRef1" type="ORG_2"/>
      <DO name="ElcRefId" type="VSG_1"/>
      <DO name="ElcMsRef1" type="ORG_2"/>
      <DO name="EcpIsldSt" type="ENS_9"/>
      <DO name="PhsConnTyp" type="ENG_10"/>
      <DO name="GndSys" type="ENG_16"/>
      <DO name="VRef" type="ASG_4"/>
      <DO name="VRefPct" type="ASG_1"/>
      <DO name="VArRtg" type="ASG_2"/>
      <DO name="VARtg" type="ASG_1"/>
      <DO name="WRtg" type="ASG_1"/>
      <DO name="VRtg" type="ASG_1"/>
      <DO name="HzNom" type="ASG_1"/>
      <DO name="VMax" type="ASG_1"/>
      <DO name="VMin" type="ASG_1"/>
      <DO name="DERMsIncl" type="SPG_1"/>
      <DO name="RefFrm" type="SPG_1"/>
      <DO name="EcpIsldAuto" type="SPG_1"/>
      <DO name="AreaEpsEcpId" type="VSG_1"/>
      <DO name="AreaEpsWMax" type="ASG_4"/>
    </LNodeType>
    <LNodeType id="DSTO_2" lnClass="DSTO">
      <DO name="NamPlt" type="LPL_3"/>
      <DO name="Beh" type="ENS_1"/>
      <DO name="Health" type="ENS_2"/>
      <DO name="Mir" type="SPS_1"/>
      <DO name="Mod" type="ENC_2"/>
      <DO name="InRef1" type="ORG_2"/>
      <DO name="ClcExp" type="SPS_1"/>
      <DO name="ClcNxtTmms" type="INS_1"/>
      <DO name="ClcStr" type="SPC_3"/>
      <DO name="ClcMth" type="ENG_1"/>
      <DO name="ClcMod" type="ENG_2"/>
      <DO name="ClcIntvTyp" type="ENG_3"/>
      <DO name="ClcIntvPer" type="ING_1"/>
      <DO name="NumSubIntv" type="ING_1"/>
      <DO name="ClcRfTyp" type="ENG_3"/>
      <DO name="ClcRfPer" type="ING_1"/>
      <DO name="ClcSrc" type="ORG_3"/>
      <DO name="InSyn" type="ORG_2"/>
      <DO name="Blk" type="SPS_1"/>
      <DO name="BlkRef1" type="ORG_2"/>
      <DO name="Loc" type="SPS_1"/>
      <DO name="LocKey" type="SPS_1"/>
      <DO name="LocSta" type="SPC_3"/>
      <DO name="CmdBlk" type="SPC_3"/>
      <DO name="OpCntRs" type="INC_1"/>
      <DO name="EEName" type="DPL_1"/>
      <DO name="EEHealth" type="ENS_2"/>
      <DO name="OpTmh" type="INS_1"/>
      <DO name="DERId1" type="VSG_1"/>
      <DO name="OutEcpRef" type="ORG_3"/>
      <DO name="EcpConnTyp" type="ENG_9"/>
      <DO name="PhsConnTyp" type="ENG_10"/>
      <DO name="DERTyp" type="ENG_11_DERTyp"/>
      <DO name="OvPFRtg" type="ASG_1"/>
      <DO name="UnPFRtg" type="ASG_1"/>
      <DO name="TmpMaxRtg" type="ASG_1"/>
      <DO name="FltRtgPct" type="ASG_1"/>
      <DO name="GndReactRtg" type="ASG_1"/>
      <DO name="FltAMaxRtg" type="ASG_1"/>
      <DO name="SelfVRtg" type="ASG_1"/>
      <DO name="FltDurMaxTms" type="ING_1"/>
      <DO name="SelfWRtg" type="ASG_1"/>
      <DO name="SelfPFRtg" type="ASG_1"/>
      <DO name="RvSeq" type="SPG_1"/>
      <DO name="SelfVRngRtg" type="ASG_1"/>
      <DO name="EfcRtgPct" type="ASG_1"/>
      <DO name="GndRisRtg" type="ASG_1"/>
      <DO name="SuscRtg" type="ASG_1"/>
      <DO name="RegClas1" type="VSG_1"/>
      <DO name="HzNomRtg1" type="ASG_1"/>
      <DO name="HzMinRtg" type="ASG_1"/>
      <DO name="HzMaxRtg" type="ASG_1"/>
      <DO name="PFSign" type="ENG_12"/>
      <DO name="OplPct" type="ING_1"/>
      <DO name="OvPF" type="ASG_1"/>
      <DO name="PFExtSet" type="SPG_1"/>
      <DO name="IsldCtlFol" type="SPG_1"/>
      <DO name="ClcTotVA" type="ENG_13"/>
      <DO name="FllBckTmExp" type="ING_1"/>
      <DO name="AvarZerWMax" type="ASG_1"/>
      <DO name="IvarZerWMax" type="ASG_1"/>
      <DO name="SelfSvcWh" type="MV_1"/>
      <DO name="VAPct" type="MV_1"/>
      <DO name="AvlUpW" type="MV_1"/>
      <DO name="AvlDnW" type="MV_1"/>
      <DO name="DEROpSt" type="ENS_8"/>
      <DO name="TestRsl" type="SPS_1"/>
      <DO name="TestAddRsl" type="ENS_7"/>
      <DO name="AuthConn" type="SPC_3"/>
      <DO name="DEROpStCtl" type="ENC_3"/>
      <DO name="CeaEgzCtl" type="SPC_3"/>
      <DO name="WSpt" type="APC_2"/>
      <DO name="VArSpt" type="APC_2"/>
      <DO name="EmgMod" type="SPC_3"/>
      <DO name="AuthDscon" type="SPC_3"/>
      <DO name="TestEna" type="SPC_3"/>
      <DO name="Test" type="SPC_3"/>
      <DO name="StrMaxTms" type="ING_1"/>
      <DO name="OffMinTms" type="ING_1"/>
      <DO name="OnMinTms" type="ING_1"/>
      <DO name="StopDlMinTms" type="ING_1"/>
      <DO name="StopMaxTms" type="ING_1"/>
      <DO name="StrDlMinTms" type="ING_2"/>
      <DO name="AutoStr" type="SPG_1"/>
      <DO name="AutoConn" type="SPG_1"/>
      <DO name="ChaAvarTot" type="MV_1"/>
      <DO name="DschAvarTot" type="MV_1"/>
      <DO name="ChaIvarTot" type="MV_1"/>
      <DO name="DschIvarTot" type="MV_1"/>
      <DO name="ChaAvarAvl" type="MV_1"/>
      <DO name="DschAvarAvl" type="MV_1"/>
      <DO name="ChaIvarAvl" type="MV_1"/>
      <DO name="DschIvarAvl" type="MV_1"/>
      <DO name="EffWh" type="MV_1"/>
      <DO name="EffWhPct" type="MV_1"/>
      <DO name="ChaWMax" type="ASG_3"/>
      <DO name="DschWMax" type="ASG_1"/>
      <DO name="ChaWRmp" type="ASG_1"/>
      <DO name="DschWRmp" type="ASG_1"/>
      <DO name="ChaVArMax" type="ASG_1"/>
      <DO name="DschVArMax" type="ASG_1"/>
      <DO name="ChaVAMax" type="ASG_1"/>
      <DO name="DschVAMax" type="ASG_1"/>
      <DO name="ChaAvarMax" type="ASG_1"/>
      <DO name="DschAvarMax" type="ASG_1"/>
      <DO name="ChaIvarMax" type="ASG_1"/>
      <DO name="DschIvarMax" type="ASG_1"/>
      <DO name="ChaVMax" type="ASG_1"/>
      <DO name="DschVMax" type="ASG_1"/>
      <DO name="ChaVMin" type="ASG_1"/>
      <DO name="DschVMin" type="ASG_1"/>
      <DO name="ChaAMax" type="ASG_1"/>
      <DO name="DschAMax" type="ASG_1"/>
      <DO name="ChaEfc" type="CSG_10"/>
      <DO name="DschEfc" type="CSG_10"/>
      <DO name="UseWhMaxPct" type="ASG_1"/>
      <DO name="UseWhMinPct" type="ASG_1"/>
      <DO name="UseWh" type="ASG_1"/>
      <DO name="ChaSrc" type="ENG_14"/>
      <DO name="ChaWOvPFMax" type="ASG_1"/>
      <DO name="DschWOvPFMax" type="ASG_1"/>
      <DO name="ChaWUnPFMax" type="ASG_1"/>
      <DO name="DschWUnPFMax" type="ASG_1"/>
      <DO name="RenChaEna" type="SPG_1"/>
      <DO name="ChaWMaxRtg" type="ASG_1"/>
      <DO name="DschWMaxRtg" type="ASG_1"/>
      <DO name="ChaWRmpRtg" type="ASG_1"/>
      <DO name="DschWRmpRtg" type="ASG_1"/>
      <DO name="ChaWOvPFRtg" type="ASG_1"/>
      <DO name="DschWOvPFRtg" type="ASG_1"/>
      <DO name="ChaWUnPFRtg" type="ASG_1"/>
      <DO name="DschWUnPFRtg" type="ASG_1"/>
      <DO name="ChaVAMaxRtg" type="ASG_1"/>
      <DO name="DschVAMaxRtg" type="ASG_1"/>
      <DO name="ChaAvarRtg" type="ASG_1"/>
      <DO name="DschAvarRtg" type="ASG_1"/>
      <DO name="ChaIvarRtg" type="ASG_1"/>
      <DO name="DschIvarRtg" type="ASG_1"/>
      <DO name="ChaVMaxRtg" type="ASG_1"/>
      <DO name="DschVMaxRtg" type="ASG_1"/>
      <DO name="ChaVMinRtg" type="ASG_1"/>
      <DO name="DschVMinRtg" type="ASG_1"/>
      <DO name="ChaAMaxRtg" type="ASG_1"/>
      <DO name="DschAMaxRtg" type="ASG_1"/>
      <DO name="WhRtg" type="ASG_1"/>
      <DO name="WhMaxRtg" type="ASG_1"/>
      <DO name="WhMinRtg" type="ASG_1"/>
      <DO name="ChaEfcRtg" type="CSG_4"/>
      <DO name="DschEfcRtg" type="CSG_10"/>
      <DO name="ChaSrcRtg" type="ENG_14"/>
      <DO name="SocHiAlm" type="SPS_1"/>
      <DO name="SocHiWrn" type="SPS_1"/>
      <DO name="SocLoAlm" type="SPS_1"/>
      <DO name="SocLoWrn" type="SPS_1"/>
      <DO name="SohLoAlm" type="SPS_1"/>
      <DO name="ChaCycCnt" type="INS_1"/>
      <DO name="InWh" type="MV_1"/>
      <DO name="OutWh" type="MV_1"/>
      <DO name="SocWh" type="MV_1"/>
      <DO name="UseSocPct" type="MV_1"/>
      <DO name="SocEffWhPct" type="MV_1"/>
      <DO name="ChaWhTot" type="MV_1"/>
      <DO name="DschWhTot" type="MV_1"/>
      <DO name="AvlDschW" type="MV_1"/>
      <DO name="AvlChaW" type="MV_1"/>
      <DO name="ChaVAPct" type="MV_1"/>
      <DO name="AvlChaWTm" type="MV_1"/>
      <DO name="AvlDschWTm" type="MV_1"/>
      <DO name="ChaWhTotRs" type="SPC_3"/>
      <DO name="DschWhTotRs" type="SPC_3"/>
      <DO name="EqGn" type="ORG_1"/>
      <DO name="EqLod" type="ORG_1"/>
      <DO name="SocHiAlsPct" type="ASG_1"/>
      <DO name="SocHiWrsPct" type="ASG_1"/>
      <DO name="SocLoAlsPct" type="ASG_1"/>
      <DO name="SocLoWrsPct" type="ASG_1"/>
      <DO name="SohLoAlsPct" type="ASG_1"/>
      <DO name="RntEffPct" type="ASG_1"/>
      <DO name="EqSto" type="ORG_3"/>
      <DO name="InclSto1" type="ORG_1"/>
      <DO name="DERUnit" type="ORG_1"/>
    </LNodeType>
    <LNodeType id="DVER_1" lnClass="DVER">
      <DO name="NamPlt" type="LPL_3"/>
      <DO name="Beh" type="ENS_1"/>
      <DO name="Health" type="ENS_2"/>
      <DO name="Mir" type="SPS_1"/>
      <DO name="Mod" type="ENC_2"/>
      <DO name="InRef1" type="ORG_1"/>
      <DO name="ClcExp" type="SPS_1"/>
      <DO name="ClcNxtTmms" type="INS_1"/>
      <DO name="ClcStr" type="SPC_6"/>
      <DO name="ClcMth" type="ENG_1"/>
      <DO name="ClcMod" type="ENG_2"/>
      <DO name="ClcIntvTyp" type="ENG_3"/>
      <DO name="ClcIntvPer" type="ING_1"/>
      <DO name="NumSubIntv" type="ING_1"/>
      <DO name="ClcRfTyp" type="ENG_3"/>
      <DO name="ClcRfPer" type="ING_1"/>
      <DO name="ClcSrc" type="ORG_2"/>
      <DO name="InSyn" type="ORG_2"/>
      <DO name="Blk" type="SPS_1"/>
      <DO name="BlkRef1" type="ORG_2"/>
      <DO name="ElcStCtlRef1" type="ORG_2"/>
      <DO name="ElcRefId" type="VSG_1"/>
      <DO name="ElcMsRef1" type="ORG_1"/>
      <DO name="InclElcRef1" type="ORG_1"/>
    </LNodeType>
    <LNodeType id="GGIO_2" lnClass="GGIO">
      <DO name="Beh" type="ENS_1"/>
      <DO name="Health" type="ENS_2"/>
      <DO name="Mod" type="ENC_4"/>
      <DO name="EEName" type="DPL_1"/>
      <DO name="EEHealth" type="ENS_2"/>
      <DO name="Loc" type="SPS_1"/>
      <DO name="IntIn1" type="INS_1"/>
      <DO name="Alm1" type="SPS_1"/>
      <DO name="Wrn1" type="SPS_1"/>
      <DO name="Ind1" type="SPS_1"/>
      <DO name="AnIn1" type="MV_2"/>
      <DO name="AnOut1" type="APC_1"/>
      <DO name="OpCntRs" type="INC_2"/>
      <DO name="LocSta" type="SPC_1"/>
      <DO name="SPCSO1" type="SPC_3"/>
      <DO name="DPCSO1" type="DPC_1"/>
      <DO name="ISCSO1" type="INC_1"/>
      <DO name="ClcStr" type="SPC_1"/>
    </LNodeType>
    <LNodeType id="LLN0_2" lnClass="LLN0">
      <DO name="NamPlt" type="LPL_1"/>
      <DO name="Beh" type="ENS_1"/>
      <DO name="Health" type="ENS_2"/>
      <DO name="Mod" type="ENC_4"/>
      <DO name="Loc" type="SPS_1"/>
      <DO name="LocSta" type="SPC_1"/>
    </LNodeType>
    <LNodeType id="MMDC_1" lnClass="MMDC">
      <DO name="NamPlt" type="LPL_2"/>
      <DO name="Beh" type="ENS_1"/>
      <DO name="Mod" type="ENC_4"/>
      <DO name="Watt" type="MV_2"/>
      <DO name="Amp" type="MV_2"/>
      <DO name="Vol" type="MV_2"/>
    </LNodeType>
    <LNodeType id="MMXU_2" lnClass="MMXU">
      <DO name="NamPlt" type="LPL_2"/>
      <DO name="Beh" type="ENS_1"/>
      <DO name="Health" type="ENS_2"/>
      <DO name="Blk" type="SPS_1"/>
      <DO name="Mod" type="ENC_4"/>
      <DO name="InRef1" type="ORG_1"/>
      <DO name="BlkRef1" type="ORG_1"/>
      <DO name="ClcExp" type="SPS_1"/>
      <DO name="ClcStr" type="SPC_1"/>
      <DO name="ClcSrc" type="ORG_1"/>
      <DO name="ClcNxtTmms" type="ING_3"/>
      <DO name="InSyn" type="ORG_1"/>
      <DO name="TotW" type="MV_2"/>
      <DO name="TotVAr" type="MV_2"/>
      <DO name="TotVA" type="MV_2"/>
      <DO name="TotPF" type="MV_2"/>
      <DO name="Hz" type="MV_2"/>
      <DO name="PPV" type="DEL_1"/>
      <DO name="PNV" type="WYE_2"/>
      <DO name="PhV" type="WYE_3"/>
      <DO name="A" type="WYE_3"/>
      <DO name="W" type="WYE_3"/>
      <DO name="VAr" type="WYE_3"/>
      <DO name="VA" type="WYE_3"/>
      <DO name="PF" type="WYE_3"/>
      <DO name="Z" type="WYE_3"/>
      <DO name="AvAPhs" type="MV_2"/>
      <DO name="AvPPVPhs" type="MV_2"/>
      <DO name="AvPhVPhs" type="MV_2"/>
      <DO name="AvWPhs" type="MV_2"/>
      <DO name="AvVAPhs" type="MV_2"/>
      <DO name="AvVArPhs" type="MV_2"/>
      <DO name="AvPFPhs" type="MV_2"/>
      <DO name="AvZPhs" type="MV_2"/>
      <DO name="MaxAPhs" type="MV_2"/>
      <DO name="MaxPPVPhs" type="MV_2"/>
      <DO name="MaxPhVPhs" type="MV_2"/>
      <DO name="MaxWPhs" type="MV_2"/>
      <DO name="MaxVAPhs" type="MV_2"/>
      <DO name="MaxVArPhs" type="MV_2"/>
      <DO name="MaxPFPhs" type="MV_2"/>
      <DO name="MaxZPhs" type="MV_2"/>
      <DO name="MinAPhs" type="MV_2"/>
      <DO name="MinPPVPhs" type="MV_2"/>
      <DO name="MinPhVPhs" type="MV_2"/>
      <DO name="MinWPhs" type="MV_2"/>
      <DO name="MinVAPhs" type="MV_2"/>
      <DO name="MinVArPhs" type="MV_2"/>
      <DO name="MinPFPhs" type="MV_2"/>
      <DO name="MinZPhs" type="MV_2"/>
      <DO name="HzRte" type="MV_2"/>
      <DO name="Mir" type="SPS_1"/>
    </LNodeType>
    <LNodeType id="PTOC_1" lnClass="PTOC">
      <DO name="Str" type="ACD_1"/>
      <DO name="Op" type="ACT_1"/>
      <DO name="Beh" type="ENS_1"/>
      <DO name="OpCntRs" type="INC_2"/>
      <DO name="DirMod" type="ENG_7"/>
      <DO name="TmACrv" type="CURVE_1"/>
      <DO name="TmAChr1" type="CSG_1"/>
      <DO name="TmMult" type="ASG_1"/>
      <DO name="MinOpTmms" type="ING_1"/>
      <DO name="MaxOpTmms" type="ING_1"/>
      <DO name="OpDlTmms" type="ING_1"/>
      <DO name="TypRsCrv" type="ENG_8"/>
      <DO name="RsDlTmms" type="ING_1"/>
    </LNodeType>
    <LNodeType id="PTOV_2" lnClass="PTOV">
      <DO name="TmVSt" type="CSD_1"/>
      <DO name="Op" type="ACT_1"/>
      <DO name="Str" type="ACD_1"/>
      <DO name="Beh" type="ENS_1"/>
      <DO name="OpCntRs" type="INC_2"/>
      <DO name="TmVCrv" type="CURVE_1"/>
      <DO name="TmVChr1" type="CSG_1"/>
      <DO name="StrVal" type="ASG_1"/>
      <DO name="TmMult" type="ASG_1"/>
      <DO name="MinOpTmms" type="ING_1"/>
      <DO name="MaxOpTmms" type="ING_1"/>
      <DO name="OpDlTmms" type="ING_1"/>
      <DO name="RsDlTmms" type="ING_1"/>
    </LNodeType>
    <LNodeType id="SBAT_1" lnClass="SBAT">
      <DO name="NamPlt" type="LPL_3"/>
      <DO name="Beh" type="ENS_1"/>
      <DO name="Health" type="ENS_2"/>
      <DO name="Mir" type="SPS_1"/>
      <DO name="Mod" type="ENC_2"/>
      <DO name="InRef1" type="ORG_2"/>
      <DO name="ClcExp" type="SPS_1"/>
      <DO name="ClcNxtTmms" type="INS_1"/>
      <DO name="ClcStr" type="SPC_3"/>
      <DO name="ClcMth" type="ENG_1"/>
      <DO name="ClcMod" type="ENG_2"/>
      <DO name="ClcIntvTyp" type="ENG_3"/>
      <DO name="ClcIntvPer" type="ING_1"/>
      <DO name="NumSubIntv" type="ING_1"/>
      <DO name="ClcRfTyp" type="ENG_3"/>
      <DO name="ClcRfPer" type="ING_1"/>
      <DO name="ClcSrc" type="ORG_3"/>
      <DO name="InSyn" type="ORG_2"/>
      <DO name="Blk" type="SPS_1"/>
      <DO name="BlkRef1" type="ORG_2"/>
      <DO name="OpCntRs" type="INC_1"/>
      <DO name="BatEF" type="SPS_1"/>
      <DO name="CelVolLoAlm" type="SPS_1"/>
      <DO name="CelVolHiAlm" type="SPS_1"/>
      <DO name="DschAmpHiAlm" type="SPS_1"/>
      <DO name="DschAmpHiWrn" type="SPS_1"/>
      <DO name="ChaAmpHiAlm" type="SPS_1"/>
      <DO name="ChaAmpHiWrn" type="SPS_1"/>
      <DO name="IntnTmpHiAlm" type="SPS_1"/>
      <DO name="IntnTmpHiWrn" type="SPS_1"/>
      <DO name="IntnTmpLoAlm" type="SPS_1"/>
      <DO name="IntnTmpLoWrn" type="SPS_1"/>
      <DO name="UnbTmpAlm" type="SPS_1"/>
      <DO name="UnbTmpWrn" type="SPS_1"/>
      <DO name="UnbVolAlm" type="SPS_1"/>
      <DO name="UnbVolWrn" type="SPS_1"/>
      <DO name="ExtTmpHiAlm" type="SPS_1"/>
      <DO name="ExtTmpLoAlm" type="SPS_1"/>
      <DO name="ExtVolHiAlm" type="SPS_1"/>
      <DO name="ExtVolLoAlm" type="SPS_1"/>
      <DO name="IntnVolHiAlm" type="SPS_1"/>
      <DO name="IntnVolLoAlm" type="SPS_1"/>
      <DO name="IntnA" type="MV_1"/>
      <DO name="IntnV" type="MV_1"/>
      <DO name="CelVolLo" type="MV_1"/>
      <DO name="CelVolHi" type="MV_1"/>
      <DO name="CelTmpMax" type="MV_1"/>
      <DO name="CelTmpMin" type="MV_1"/>
      <DO name="IntnAmp" type="MV_1"/>
      <DO name="IntnTmp1" type="MV_1"/>
      <DO name="ExtTmp" type="MV_1"/>
      <DO name="ExtVol" type="MV_1"/>
      <DO name="IntnVol" type="MV_1"/>
      <DO name="CelVolRs" type="SPC_3"/>
      <DO name="CelVolLoAls" type="ASG_1"/>
      <DO name="CelVolHiAls" type="ASG_1"/>
      <DO name="DschAmpHiAls" type="ASG_1"/>
      <DO name="DschAmpHiWrs" type="ASG_1"/>
      <DO name="ChaAmpHiAls" type="ASG_1"/>
      <DO name="ChaAmpHiWrs" type="ASG_1"/>
      <DO name="IntnTmpHiAls" type="ASG_1"/>
      <DO name="IntnTmpHiWrs" type="ASG_1"/>
      <DO name="IntnTmpLoAls" type="ASG_1"/>
      <DO name="IntnTmpLoWrs" type="ASG_1"/>
      <DO name="UnbTmpAls" type="ASG_1"/>
      <DO name="UnbTmpWrs" type="ASG_1"/>
      <DO name="UnbVolAls" type="ASG_1"/>
      <DO name="UnbVolWrs" type="ASG_1"/>
      <DO name="ExtTmpHiAls" type="ASG_1"/>
      <DO name="ExtTmpLoAls" type="ASG_1"/>
      <DO name="ExtVolHiAls" type="ASG_1"/>
      <DO name="ExtVolLoAls" type="ASG_1"/>
      <DO name="IntnVolMxLim" type="ASG_1"/>
      <DO name="IntnVolMnLim" type="ASG_1"/>
      <DO name="IntnVolHiAls" type="ASG_1"/>
      <DO name="IntnVolLoAls" type="ASG_1"/>
    </LNodeType>
    <LNodeType id="XCBR_1" lnClass="XCBR">
      <DO name="NamPlt" type="LPL_2"/>
      <DO name="Beh" type="ENS_1"/>
      <DO name="Mod" type="ENC_4"/>
      <DO name="EEName" type="DPL_1"/>
      <DO name="EEHealth" type="ENS_2"/>
      <DO name="LocKey" type="SPS_1"/>
      <DO name="Loc" type="SPS_1"/>
      <DO name="OpCnt" type="INS_1"/>
      <DO name="CBOpCap" type="ENS_3"/>
      <DO name="POWCap" type="ENS_4"/>
      <DO name="MaxOpCap" type="INS_1"/>
      <DO name="Dsc" type="SPS_1"/>
      <DO name="SumSwARs" type="BCR_2"/>
      <DO name="LocSta" type="SPC_3"/>
      <DO name="Pos" type="DPC_3"/>
      <DO name="BlkOpn" type="SPC_3"/>
      <DO name="BlkCls" type="SPC_6"/>
      <DO name="ChaMotEna" type="SPC_3"/>
      <DO name="CBTmms" type="ING_1"/>
    </LNodeType>
    <LNodeType id="XSWI_1" lnClass="XSWI">
      <DO name="EEName" type="DPL_1"/>
      <DO name="NamPlt" type="LPL_2"/>
      <DO name="SwTyp" type="ENS_5"/>
      <DO name="SwOpCap" type="ENS_6"/>
      <DO name="Loc" type="SPS_1"/>
      <DO name="LocKey" type="SPS_1"/>
      <DO name="OpCnt" type="INS_1"/>
      <DO name="Dsc" type="SPS_1"/>
      <DO name="EEHealth" type="ENS_2"/>
      <DO name="Beh" type="ENS_1"/>
      <DO name="LocSta" type="SPC_3"/>
      <DO name="Pos" type="DPC_1"/>
      <DO name="BlkOpn" type="SPC_3"/>
      <DO name="BlkCls" type="SPC_3"/>
      <DO name="ChaMotEna" type="SPC_3"/>
    </LNodeType>
    <LNodeType id="ZBAT_2" lnClass="ZBAT">
      <DO name="NamPlt" type="LPL_2"/>
      <DO name="Beh" type="ENS_1"/>
      <DO name="Health" type="ENS_2"/>
      <DO name="Blk" type="SPS_1"/>
      <DO name="Mod" type="ENC_4"/>
      <DO name="InRef1" type="ORG_1"/>
      <DO name="BlkRef1" type="ORG_1"/>
      <DO name="EEName" type="DPL_1"/>
      <DO name="EEHealth" type="ENS_2"/>
      <DO name="OpTmh" type="INS_1"/>
      <DO name="TestRsl" type="SPS_1"/>
      <DO name="BatHi" type="SPS_1"/>
      <DO name="BatLo" type="SPS_1"/>
      <DO name="Vol" type="MV_2"/>
      <DO name="VolChgRte" type="MV_2"/>
      <DO name="Amp" type="MV_2"/>
      <DO name="BatTest" type="SPC_2"/>
      <DO name="LoBatVal" type="ASG_5"/>
      <DO name="HiBatVal" type="ASG_5"/>
      <DO name="BatSt" type="SPS_2"/>
      <DO name="BatTyp" type="ENG_4"/>
      <DO name="ClcExp" type="SPS_1"/>
      <DO name="ClcIntvPer" type="ING_1"/>
      <DO name="ClcIntvTyp" type="ENG_3"/>
      <DO name="ClcMod" type="ENG_2"/>
      <DO name="ClcMth" type="ENG_1"/>
      <DO name="ClcNxtTmms" type="INS_1"/>
      <DO name="ClcRfPer" type="ING_1"/>
      <DO name="ClcRfTyp" type="ENG_3"/>
      <DO name="ClcSrc" type="ORG_1"/>
      <DO name="ClcStr" type="SPC_1"/>
      <DO name="InSyn" type="ORG_1"/>
      <DO name="Mir" type="SPS_1"/>
      <DO name="NumSubIntv" type="ING_1"/>
    </LNodeType>
    <LNodeType id="ZBTC_2" lnClass="ZBTC">
      <DO name="Beh" type="ENS_1"/>
      <DO name="BatChaMod" type="ENG_6"/>
      <DO name="BatChaSt" type="ENG_5"/>
    </LNodeType>
    <LNodeType id="LPHD_2" lnClass="LPHD">
      <DO name="NamPlt" type="LPL_2"/>
      <DO name="PhyNam" type="DPL_1"/>
      <DO name="PhyHealth" type="ENS_2"/>
      <DO name="OutOv" type="SPS_1"/>
      <DO name="Proxy" type="SPS_1"/>
      <DO name="InOv" type="SPS_1"/>
      <DO name="OpTmh" type="INS_1"/>
      <DO name="NumPwrUp" type="INS_1"/>
      <DO name="WrmStr" type="INS_1"/>
      <DO name="WacTrg" type="INS_1"/>
      <DO name="PwrUp" type="SPS_1"/>
      <DO name="PwrDn" type="SPS_1"/>
      <DO name="PwrSupAlm" type="SPS_1"/>
      <DO name="RsStat" type="SPC_1"/>
      <DO name="Sim" type="SPC_1"/>
    </LNodeType>
    <DOType id="ACD_1" cdc="ACD">
      <DA name="general" bType="BOOLEAN" fc="ST"/>
      <DA name="dirGeneral" bType="Enum" fc="ST" type="FaultDirectionKind"/>
      <DA name="q" bType="Quality" fc="ST"/>
      <DA name="t" bType="Timestamp" fc="ST"/>
    </DOType>
    <DOType id="ACT_1" cdc="ACT">
      <DA name="general" bType="BOOLEAN" fc="ST"/>
      <DA name="q" bType="Quality" fc="ST"/>
      <DA name="t" bType="Timestamp" fc="ST"/>
    </DOType>
    <DOType id="APC_1" cdc="APC">
      <DA name="ctlModel" bType="Enum" fc="CF" type="CtlModelKind"/>
    </DOType>
    <DOType id="APC_2" cdc="APC">
      <DA name="origin" bType="Struct" fc="MX" type="Originator_1"/>
      <DA name="ctlNum" bType="INT8U" fc="MX"/>
      <DA name="q" bType="Quality" fc="MX"/>
      <DA name="t" bType="Timestamp" fc="MX"/>
      <DA name="ctlModel" bType="Enum" fc="CF" type="CtlModelKind"/>
      <DA name="Oper" bType="Struct" fc="CO" type="OperAnalog_1"/>
      <DA name="Cancel" bType="Struct" fc="CO" type="CancelAnalog_1"/>
    </DOType>
    <DOType id="ASG_1" cdc="ASG">
      <DA name="setMag" bType="Struct" fc="SP" type="AnalogueValue_1"/>
      <DA name="units" bType="Struct" fc="CF" type="Unit_1"/>
      <DA name="sVC" bType="Struct" fc="CF" type="ScaledValueConfig_1"/>
      <DA name="minVal" bType="Struct" fc="CF" type="AnalogueValue_1"/>
      <DA name="maxVal" bType="Struct" fc="CF" type="AnalogueValue_1"/>
      <DA name="stepSize" bType="Struct" fc="CF" type="AnalogueValue_1"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="ASG_2" cdc="ASG">
      <DA name="setMag" bType="Struct" fc="SP" type="AnalogueValue_1"/>
      <DA name="minVal" bType="Struct" fc="CF" type="AnalogueValue_1"/>
      <DA name="maxVal" bType="Struct" fc="CF" type="AnalogueValue_1"/>
      <DA name="stepSize" bType="Struct" fc="CF" type="AnalogueValue_1"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="ASG_3" cdc="ASG">
      <DA name="setMag" bType="Struct" fc="SP" type="AnalogueValue_2" dchg="true"/>
      <DA name="units" bType="Struct" fc="CF" type="Unit_1" dchg="true"/>
      <DA name="sVC" bType="Struct" fc="CF" type="ScaledValueConfig_1" dchg="true"/>
      <DA name="minVal" bType="Struct" fc="CF" type="AnalogueValue_1" dchg="true"/>
      <DA name="maxVal" bType="Struct" fc="CF" type="AnalogueValue_1" dchg="true"/>
      <DA name="stepSize" bType="Struct" fc="CF" type="AnalogueValue_1" dchg="true"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="ASG_4" cdc="ASG">
      <DA name="setMag" bType="Struct" fc="SP" type="AnalogueValue_2"/>
      <DA name="minVal" bType="Struct" fc="CF" type="AnalogueValue_1"/>
      <DA name="maxVal" bType="Struct" fc="CF" type="AnalogueValue_1"/>
      <DA name="stepSize" bType="Struct" fc="CF" type="AnalogueValue_1"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="ASG_5" cdc="ASG">
      <DA name="setMag" dchg="true" bType="Struct" fc="SP" type="AnalogueValue_2"/>
      <DA name="units" dchg="true" bType="Struct" fc="CF" type="Unit_1"/>
      <DA name="sVC" dchg="true" bType="Struct" fc="CF" type="ScaledValueConfig_1"/>
      <DA name="minVal" dchg="true" bType="Struct" fc="CF" type="AnalogueValue_2"/>
      <DA name="maxVal" dchg="true" bType="Struct" fc="CF" type="AnalogueValue_2"/>
      <DA name="stepSize" dchg="true" bType="Struct" fc="CF" type="AnalogueValue_2"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="BCR_2" cdc="BCR">
      <DA name="actVal" dchg="true" bType="INT64" fc="ST"/>
      <DA name="q" qchg="true" bType="Quality" fc="ST"/>
      <DA name="t" bType="Timestamp" fc="ST"/>
      <DA name="pulsQty" dchg="true" bType="FLOAT32" fc="CF"/>
    </DOType>
    <DOType id="CMV_2" cdc="CMV">
      <DA name="cVal" bType="Struct" fc="MX" type="Vector_2" dchg="false" dupd="true"/>
      <DA name="q" bType="Quality" fc="MX" qchg="true"/>
      <DA name="t" bType="Timestamp" fc="MX"/>
    </DOType>
    <DOType id="CMV_3" cdc="CMV">
      <DA name="cVal" bType="Struct" fc="MX" type="Vector_3" dchg="true"/>
      <DA name="q" bType="Quality" fc="MX" qchg="true"/>
      <DA name="t" bType="Timestamp" fc="MX"/>
    </DOType>
    <DOType id="CSD_1" cdc="CSD">
      <DA name="xUnits" bType="Struct" fc="DC" type="Unit_1"/>
      <DA name="xD" bType="VisString255" fc="DC"/>
      <DA name="yUnits" bType="Struct" fc="DC" type="Unit_1"/>
      <DA name="yD" bType="VisString255" fc="DC"/>
      <DA name="numPts" bType="INT16U" fc="DC"/>
      <DA name="crvPts" count="32" bType="Struct" fc="DC" type="Point_1"/>
      <DA name="maxPts" bType="INT16U" fc="CF"/>
    </DOType>
    <DOType id="CSG_1" cdc="CSG">
      <DA name="pointZ" bType="FLOAT32" fc="SP"/>
      <DA name="numPts" bType="INT16U" fc="SP"/>
      <DA name="crvPts" count="32" bType="Struct" fc="SP" type="Point_1"/>
      <DA name="xUnits" bType="Struct" fc="CF" type="Unit_1"/>
      <DA name="yUnits" bType="Struct" fc="CF" type="Unit_1"/>
      <DA name="zUnits" bType="Struct" fc="CF" type="Unit_1"/>
      <DA name="maxPts" bType="INT16U" fc="CF"/>
      <DA name="xD" bType="VisString255" fc="DC"/>
      <DA name="xDU" bType="Unicode255" fc="DC"/>
      <DA name="yD" bType="VisString255" fc="DC"/>
      <DA name="yDU" bType="Unicode255" fc="DC"/>
      <DA name="zD" bType="VisString255" fc="DC"/>
      <DA name="zDU" bType="Unicode255" fc="DC"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="CSG_10" cdc="CSG">
      <DA name="pointZ" bType="FLOAT32" fc="SP"/>
      <DA name="numPts" bType="INT16U" fc="SP"/>
      <DA name="crvPts" count="32" bType="Struct" fc="SP" type="Point_1"/>
      <DA name="xUnits" bType="Struct" fc="CF" type="Unit_1"/>
      <DA name="yUnits" bType="Struct" fc="CF" type="Unit_1"/>
      <DA name="maxPts" bType="INT16U" fc="CF"/>
      <DA name="xD" bType="VisString255" fc="DC"/>
      <DA name="yD" bType="VisString255" fc="DC"/>
      <DA name="zD" bType="VisString255" fc="DC"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="CSG_4" cdc="CSG">
      <DA name="pointZ" bType="FLOAT32" fc="SP"/>
      <DA name="numPts" bType="INT16U" fc="SP"/>
      <DA name="crvPts" count="32" bType="Struct" fc="SP" type="Point_1"/>
      <DA name="xUnits" bType="Struct" fc="CF" type="Unit_1"/>
      <DA name="yUnits" bType="Struct" fc="CF" type="Unit_1"/>
      <DA name="maxPts" bType="INT16U" fc="CF"/>
      <DA name="xD" bType="VisString255" fc="DC"/>
      <DA name="yD" bType="VisString255" fc="DC"/>
      <DA name="zD" bType="VisString255" fc="DC"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="CSG_6" cdc="CSG">
      <DA name="pointZ" bType="FLOAT32" fc="SP"/>
      <DA name="numPts" bType="INT16U" fc="SP"/>
      <DA name="crvPts" count="32" bType="Struct" fc="SP" type="Point_1"/>
      <DA name="xUnits" bType="Struct" fc="CF" type="Unit_1"/>
      <DA name="yUnits" bType="Struct" fc="CF" type="Unit_1"/>
      <DA name="zUnits" bType="Struct" fc="CF" type="Unit_1"/>
      <DA name="maxPts" bType="INT16U" fc="CF"/>
      <DA name="xD" bType="VisString255" fc="DC"/>
      <DA name="yD" bType="VisString255" fc="DC"/>
      <DA name="zD" bType="VisString255" fc="DC"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="CUG_1" cdc="CUG">
      <DA name="cur" bType="Currency" fc="SP"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="CUG_2" cdc="CUG">
      <DA name="cur" dchg="true" bType="Currency" fc="SP"/>
    </DOType>
    <DOType id="CURVE_1" cdc="CURVE">
      <DA name="setCharact" bType="Enum" fc="SP" type="CurveCharKind"/>
      <DA name="setParA" bType="FLOAT32" fc="SP"/>
      <DA name="setParB" bType="FLOAT32" fc="SP"/>
      <DA name="setParC" bType="FLOAT32" fc="SP"/>
      <DA name="setParD" bType="FLOAT32" fc="SP"/>
      <DA name="setParE" bType="FLOAT32" fc="SP"/>
      <DA name="setParF" bType="FLOAT32" fc="SP"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="DEL_1" cdc="DEL">
      <SDO name="phsAB" type="CMV_2"/>
      <SDO name="phsBC" type="CMV_2"/>
      <SDO name="phsCA" type="CMV_2"/>
    </DOType>
    <DOType id="DPC_1" cdc="DPC">
      <DA name="origin" bType="Struct" fc="ST" type="Originator_1"/>
      <DA name="ctlNum" bType="INT8U" fc="ST"/>
      <DA name="stVal" bType="Dbpos" fc="ST" dchg="true"/>
      <DA name="q" bType="Quality" fc="ST" qchg="true"/>
      <DA name="t" bType="Timestamp" fc="ST"/>
      <DA name="ctlModel" bType="Enum" fc="CF" type="CtlModelKind" dchg="true"/>
      <DA name="Oper" bType="Struct" fc="CO" type="OperBOOLEAN_1"/>
      <DA name="Cancel" bType="Struct" fc="CO" type="CancelBOOLEAN_1"/>
    </DOType>
    <DOType id="DPC_3" cdc="DPC">
      <DA name="stVal" bType="Dbpos" fc="ST" dchg="true"/>
      <DA name="q" bType="Quality" fc="ST" qchg="true"/>
      <DA name="t" bType="Timestamp" fc="ST"/>
      <DA name="ctlModel" bType="Enum" fc="CF" type="CtlModelKind" dchg="true"/>
      <DA name="Oper" bType="Struct" fc="CO" type="OperBOOLEAN_2"/>
      <DA name="Cancel" bType="Struct" fc="CO" type="CancelBOOLEAN_2"/>
    </DOType>
    <DOType id="DPL_1" cdc="DPL">
      <DA name="vendor" bType="VisString255" fc="DC"/>
    </DOType>
    <DOType id="ENC_2" cdc="ENC">
      <DA name="origin" bType="Struct" fc="ST" type="Originator_1"/>
      <DA name="ctlNum" bType="INT8U" fc="ST"/>
      <DA name="stVal" bType="Enum" fc="ST" type="BehaviourModeKind"/>
      <DA name="q" bType="Quality" fc="ST"/>
      <DA name="t" bType="Timestamp" fc="ST"/>
      <DA name="ctlModel" bType="Enum" fc="CF" type="CtlModelKind"/>
      <DA name="Oper" bType="Struct" fc="CO" type="OperEnum_1"/>
      <DA name="Cancel" bType="Struct" fc="CO" type="CancelEnum_1"/>
    </DOType>
    <DOType id="ENC_3" cdc="ENC">
      <DA name="origin" bType="Struct" fc="ST" type="Originator_1"/>
      <DA name="ctlNum" bType="INT8U" fc="ST"/>
      <DA name="stVal" bType="Enum" fc="ST" type="DERStateTransitionKind"/>
      <DA name="q" bType="Quality" fc="ST"/>
      <DA name="t" bType="Timestamp" fc="ST"/>
      <DA name="ctlModel" bType="Enum" fc="CF" type="CtlModelKind"/>
      <DA name="Oper" bType="Struct" fc="CO" type="OperEnum_2"/>
      <DA name="Cancel" bType="Struct" fc="CO" type="CancelEnum_2"/>
    </DOType>
    <DOType id="ENC_4" cdc="ENC">
      <DA name="stVal" dchg="true" bType="Enum" fc="ST" type="BehaviourModeKind"/>
      <DA name="q" qchg="true" bType="Quality" fc="ST"/>
      <DA name="t" bType="Timestamp" fc="ST"/>
      <DA name="ctlModel" dchg="true" bType="Enum" fc="CF" type="CtlModelKind"/>
      <DA name="Oper" bType="Struct" fc="CO" type="OperEnum_1"/>
      <DA name="Cancel" bType="Struct" fc="CO" type="CancelEnum_1"/>
    </DOType>
    <DOType id="ENG_1" cdc="ENG">
      <DA name="setVal" bType="Enum" fc="SP" type="CalcMethodKind"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="ENG_10" cdc="ENG">
      <DA name="setVal" bType="Enum" fc="SP" type="PhaseKind" dchg="true"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="ENG_11_DERTyp" cdc="ENG">
      <DA name="setVal" bType="Enum" fc="SP" type="DERUnitKind" dchg="true"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="ENG_12" cdc="ENG">
      <DA name="setVal" bType="Enum" fc="SP" type="PFSignKind"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="ENG_13" cdc="ENG">
      <DA name="setVal" bType="Enum" fc="SP" type="STotalCalcMethodKind"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="ENG_14" cdc="ENG">
      <DA name="setVal" bType="Enum" fc="SP" type="ChargeSourceKind"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="ENG_15" cdc="ENG">
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="ENG_16" cdc="ENG">
      <DA name="setVal" bType="Enum" fc="SP" type="GroundingSystemKind"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="ENG_2" cdc="ENG">
      <DA name="setVal" bType="Enum" fc="SP" type="CalcModeKind"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="ENG_3" cdc="ENG">
      <DA name="setVal" bType="Enum" fc="SP" type="CalcIntervalKind"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="ENG_4" cdc="ENG">
      <DA name="setVal" bType="Enum" fc="SP" type="BatteryTypeKind" dchg="true"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="ENG_5" cdc="ENG">
      <DA name="setVal" bType="Enum" fc="SP" type="BatteryChargerChargingModeStatusKind"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="ENG_6" cdc="ENG">
      <DA name="setVal" bType="Enum" fc="SP" type="BatteryChargerModeSettingKind"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="ENG_7" cdc="ENG">
      <DA name="setVal" bType="Enum" fc="SP" type="DirectionModeKind"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="ENG_8" cdc="ENG">
      <DA name="setVal" bType="Enum" fc="SP" type="ResetCurveKind"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="ENG_9" cdc="ENG">
      <DA name="setVal" bType="Enum" fc="SP" type="ECPConnKind"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="ENS_2" cdc="ENS">
      <DA name="stVal" bType="Enum" fc="ST" type="HealthKind"/>
      <DA name="q" bType="Quality" fc="ST"/>
      <DA name="t" bType="Timestamp" fc="ST"/>
    </DOType>
    <DOType id="ENS_3" cdc="ENS">
      <DA name="stVal" bType="Enum" fc="ST" type="BreakerOpCapabilityKind"/>
      <DA name="q" bType="Quality" fc="ST"/>
      <DA name="t" bType="Timestamp" fc="ST"/>
    </DOType>
    <DOType id="ENS_4" cdc="ENS">
      <DA name="stVal" bType="Enum" fc="ST" type="POWSwitchingCapabilityKind"/>
      <DA name="q" bType="Quality" fc="ST"/>
      <DA name="t" bType="Timestamp" fc="ST"/>
    </DOType>
    <DOType id="ENS_5" cdc="ENS">
      <DA name="stVal" bType="Enum" fc="ST" type="SwitchTypeKind" dchg="false" dupd="false"/>
      <DA name="q" bType="Quality" fc="ST" qchg="true"/>
      <DA name="t" bType="Timestamp" fc="ST"/>
    </DOType>
    <DOType id="ENS_6" cdc="ENS">
      <DA name="stVal" bType="Enum" fc="ST" type="SwitchingCapabilityKind" dchg="false" dupd="false"/>
      <DA name="q" bType="Quality" fc="ST" qchg="true"/>
      <DA name="t" bType="Timestamp" fc="ST"/>
    </DOType>
    <DOType id="ENS_7" cdc="ENS">
      <DA name="stVal" bType="Enum" fc="ST" type="EquipmentTestResultKind"/>
      <DA name="q" bType="Quality" fc="ST"/>
      <DA name="t" bType="Timestamp" fc="ST"/>
    </DOType>
    <DOType id="ENS_8" cdc="ENS">
      <DA name="stVal" bType="Enum" fc="ST" type="DERStateKind"/>
      <DA name="q" bType="Quality" fc="ST"/>
      <DA name="t" bType="Timestamp" fc="ST"/>
    </DOType>
    <DOType id="ENS_9" cdc="ENS">
      <DA name="stVal" bType="Enum" fc="ST" type="ECPIslandStateKind"/>
      <DA name="q" bType="Quality" fc="ST"/>
      <DA name="t" bType="Timestamp" fc="ST"/>
    </DOType>
    <DOType id="INC_1" cdc="INC">
      <DA name="origin" bType="Struct" fc="ST" type="Originator_1"/>
      <DA name="ctlNum" bType="INT8U" fc="ST"/>
      <DA name="stVal" bType="INT32" fc="ST"/>
      <DA name="q" bType="Quality" fc="ST"/>
      <DA name="t" bType="Timestamp" fc="ST"/>
      <DA name="ctlModel" bType="Enum" fc="CF" type="CtlModelKind"/>
      <DA name="Oper" bType="Struct" fc="CO" type="OperINT32_1"/>
      <DA name="Cancel" bType="Struct" fc="CO" type="CancelINT32_1"/>
    </DOType>
    <DOType id="INC_2" cdc="INC">
      <DA name="stVal" bType="INT32" fc="ST"/>
      <DA name="q" bType="Quality" fc="ST"/>
      <DA name="t" bType="Timestamp" fc="ST"/>
      <DA name="ctlModel" bType="Enum" fc="CF" type="CtlModelKind"/>
    </DOType>
    <DOType id="ING_1" cdc="ING">
      <DA name="setVal" bType="INT32" fc="SP"/>
      <DA name="minVal" bType="INT32" fc="CF"/>
      <DA name="maxVal" bType="INT32" fc="CF"/>
      <DA name="stepSize" bType="INT32U" fc="CF"/>
      <DA name="units" bType="Struct" fc="CF" type="Unit_1"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="ING_2" cdc="ING">
      <DA name="setVal" bType="INT32" fc="SP"/>
      <DA name="minVal" bType="INT32" fc="CF"/>
      <DA name="maxVal" bType="INT32" fc="CF"/>
      <DA name="units" bType="Struct" fc="CF" type="Unit_1"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="ING_3" cdc="ING">
      <DA name="setVal" dchg="true" bType="INT32" fc="SP"/>
    </DOType>
    <DOType id="INS_1" cdc="INS">
      <DA name="stVal" bType="INT32" fc="ST"/>
      <DA name="q" bType="Quality" fc="ST"/>
      <DA name="t" bType="Timestamp" fc="ST"/>
    </DOType>
    <DOType id="LPL_1" cdc="LPL">
      <DA name="vendor" bType="VisString255" fc="DC"/>
      <DA name="swRev" bType="VisString255" fc="DC"/>
      <DA name="ldNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="LPL_2" cdc="LPL">
      <DA name="vendor" bType="VisString255" fc="DC"/>
      <DA name="swRev" bType="VisString255" fc="DC"/>
    </DOType>
    <DOType id="LPL_3" cdc="LPL">
      <DA name="vendor" bType="VisString255" fc="DC"/>
      <DA name="swRev" bType="VisString255" fc="DC"/>
      <DA name="lnNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="MV_1" cdc="MV">
      <DA name="mag" bType="Struct" fc="MX" type="AnalogueValue_1" dchg="false" dupd="true"/>
      <DA name="q" bType="Quality" fc="MX" qchg="true"/>
      <DA name="t" bType="Timestamp" fc="MX"/>
    </DOType>
    <DOType id="MV_2" cdc="MV">
      <DA name="mag" bType="Struct" fc="MX" type="AnalogueValue_2" dchg="false" dupd="true"/>
      <DA name="q" bType="Quality" fc="MX"/>
      <DA name="t" bType="Timestamp" fc="MX"/>
    </DOType>
    <DOType id="ORG_1" cdc="ORG">
      <DA name="setSrcRef" bType="ObjRef" fc="SP"/>
    </DOType>
    <DOType id="ORG_2" cdc="ORG">
      <DA name="setSrcRef" bType="ObjRef" fc="SP"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="ORG_3" cdc="ORG">
      <DA name="setSrcRef" bType="ObjRef" fc="SP" dchg="true"/>
      <DA name="setTstRef" bType="ObjRef" fc="SP" dchg="true"/>
      <DA name="setSrcCB" bType="ObjRef" fc="SP" dchg="true"/>
      <DA name="setTstCB" bType="ObjRef" fc="SP" dchg="true"/>
      <DA name="intAddr" bType="VisString255" fc="SP" dchg="true"/>
      <DA name="tstEna" bType="BOOLEAN" fc="SP" dchg="true"/>
      <DA name="purpose" bType="VisString255" fc="DC"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="SPC_1" cdc="SPC">
      <DA name="ctlModel" bType="Enum" fc="CF" type="CtlModelKind"/>
    </DOType>
    <DOType id="SPC_2" cdc="SPC">
      <DA name="origin" bType="Struct" fc="ST" type="Originator_1"/>
      <DA name="ctlNum" bType="INT8U" fc="ST"/>
      <DA name="stVal" bType="BOOLEAN" fc="ST"/>
      <DA name="q" bType="Quality" fc="ST"/>
      <DA name="t" bType="Timestamp" fc="ST"/>
      <DA name="ctlModel" bType="Enum" fc="CF" type="CtlModelKind"/>
      <DA name="Oper" bType="Struct" fc="CO" type="OperBOOLEAN_1"/>
    </DOType>
    <DOType id="SPC_3" cdc="SPC">
      <DA name="origin" bType="Struct" fc="ST" type="Originator_1"/>
      <DA name="ctlNum" bType="INT8U" fc="ST"/>
      <DA name="stVal" bType="BOOLEAN" fc="ST" dchg="true"/>
      <DA name="q" bType="Quality" fc="ST" qchg="true"/>
      <DA name="t" bType="Timestamp" fc="ST"/>
      <DA name="ctlModel" bType="Enum" fc="CF" type="CtlModelKind" dchg="true"/>
      <DA name="Oper" bType="Struct" fc="CO" type="OperBOOLEAN_1"/>
      <DA name="Cancel" bType="Struct" fc="CO" type="CancelBOOLEAN_1"/>
    </DOType>
    <DOType id="SPC_4" cdc="SPC">
      <DA name="origin" bType="Struct" fc="ST" type="Originator_1"/>
      <DA name="ctlNum" bType="INT8U" fc="ST"/>
      <DA name="stVal" bType="BOOLEAN" fc="ST"/>
      <DA name="q" bType="Quality" fc="ST"/>
      <DA name="t" bType="Timestamp" fc="ST"/>
      <DA name="ctlModel" bType="Enum" fc="CF" type="CtlModelKind"/>
    </DOType>
    <DOType id="SPC_6" cdc="SPC">
      <DA name="origin" bType="Struct" fc="ST" type="Originator_1"/>
      <DA name="ctlNum" bType="INT8U" fc="ST"/>
      <DA name="stVal" bType="BOOLEAN" fc="ST" dchg="true"/>
      <DA name="q" bType="Quality" fc="ST" qchg="true"/>
      <DA name="t" bType="Timestamp" fc="ST"/>
      <DA name="ctlModel" bType="Enum" fc="CF" type="CtlModelKind" dchg="true"/>
      <DA name="Oper" bType="Struct" fc="CO" type="OperBOOLEAN_2"/>
      <DA name="Cancel" bType="Struct" fc="CO" type="CancelBOOLEAN_2"/>
    </DOType>
    <DOType id="SPG_1" cdc="SPG">
      <DA name="setVal" bType="BOOLEAN" fc="SP"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="SPS_1" cdc="SPS">
      <DA name="stVal" bType="BOOLEAN" fc="ST"/>
      <DA name="q" bType="Quality" fc="ST"/>
      <DA name="t" bType="Timestamp" fc="ST"/>
    </DOType>
    <DOType id="SPS_2" cdc="SPS">
      <DA name="stVal" bType="BOOLEAN" fc="ST"/>
      <DA name="q" bType="Quality" fc="ST"/>
      <DA name="t" bType="Timestamp" fc="ST"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="VSG_1" cdc="VSG">
      <DA name="setVal" bType="VisString255" fc="SP"/>
      <DA name="d" bType="VisString255" fc="DC"/>
      <DA name="dU" bType="Unicode255" fc="DC"/>
      <DA name="cdcName" bType="VisString255" fc="EX"/>
      <DA name="dataNs" bType="VisString255" fc="EX"/>
    </DOType>
    <DOType id="WYE_2" cdc="WYE">
      <SDO name="phsA" type="CMV_2"/>
      <SDO name="phsB" type="CMV_3"/>
      <SDO name="phsC" type="CMV_2"/>
    </DOType>
    <DOType id="WYE_3" cdc="WYE">
      <SDO name="phsA" type="CMV_2"/>
      <SDO name="phsB" type="CMV_2"/>
      <SDO name="phsC" type="CMV_2"/>
    </DOType>
    <DOType id="ENS_1" cdc="ENS">
      <DA name="stVal" bType="Enum" fc="ST" type="BehaviourModeKind"/>
      <DA name="q" bType="Quality" fc="ST"/>
      <DA name="t" bType="Timestamp" fc="ST"/>
    </DOType>
    <DAType id="AnalogueValue_2">
      <BDA name="i" bType="INT32"/>
      <BDA name="f" bType="FLOAT32"/>
    </DAType>
    <DAType id="CancelAnalog_1">
      <BDA name="ctlVal" bType="Struct" type="AnalogueValue_1"/>
      <BDA name="origin" bType="Struct" type="Originator_1"/>
      <BDA name="ctlNum" bType="INT8U"/>
      <BDA name="T" bType="Timestamp"/>
      <BDA name="Test" bType="BOOLEAN"/>
    </DAType>
    <DAType id="CancelBOOLEAN_1">
      <BDA name="ctlVal" bType="BOOLEAN"/>
      <BDA name="origin" bType="Struct" type="Originator_1"/>
      <BDA name="ctlNum" bType="INT8U"/>
      <BDA name="T" bType="Timestamp"/>
      <BDA name="Test" bType="BOOLEAN"/>
    </DAType>
    <DAType id="CancelBOOLEAN_2">
      <BDA name="ctlVal" bType="BOOLEAN"/>
      <BDA name="operTm" bType="Timestamp"/>
      <BDA name="origin" bType="Struct" type="Originator_1"/>
      <BDA name="ctlNum" bType="INT8U"/>
      <BDA name="T" bType="Timestamp"/>
      <BDA name="Test" bType="BOOLEAN"/>
    </DAType>
    <DAType id="CancelEnum_1">
      <BDA name="ctlVal" bType="Enum" type="BehaviourModeKind"/>
      <BDA name="origin" bType="Struct" type="Originator_1"/>
      <BDA name="ctlNum" bType="INT8U"/>
      <BDA name="T" bType="Timestamp"/>
      <BDA name="Test" bType="BOOLEAN"/>
    </DAType>
    <DAType id="CancelEnum_2">
      <BDA name="ctlVal" bType="Enum" type="DERStateTransitionKind"/>
      <BDA name="origin" bType="Struct" type="Originator_1"/>
      <BDA name="ctlNum" bType="INT8U"/>
      <BDA name="T" bType="Timestamp"/>
      <BDA name="Test" bType="BOOLEAN"/>
    </DAType>
    <DAType id="CancelINT32_1">
      <BDA name="ctlVal" bType="INT32"/>
      <BDA name="origin" bType="Struct" type="Originator_1"/>
      <BDA name="ctlNum" bType="INT8U"/>
      <BDA name="T" bType="Timestamp"/>
      <BDA name="Test" bType="BOOLEAN"/>
    </DAType>
    <DAType id="OperAnalog_1">
      <BDA name="ctlVal" bType="Struct" type="AnalogueValue_1"/>
      <BDA name="origin" bType="Struct" type="Originator_1"/>
      <BDA name="ctlNum" bType="INT8U"/>
      <BDA name="T" bType="Timestamp"/>
      <BDA name="Test" bType="BOOLEAN"/>
      <BDA name="Check" bType="Check"/>
    </DAType>
    <DAType id="OperBOOLEAN_1">
      <BDA name="ctlVal" bType="BOOLEAN"/>
      <BDA name="origin" bType="Struct" type="Originator_1"/>
      <BDA name="ctlNum" bType="INT8U"/>
      <BDA name="T" bType="Timestamp"/>
      <BDA name="Test" bType="BOOLEAN"/>
      <BDA name="Check" bType="Check"/>
    </DAType>
    <DAType id="OperBOOLEAN_2">
      <BDA name="ctlVal" bType="BOOLEAN"/>
      <BDA name="operTm" bType="Timestamp"/>
      <BDA name="origin" bType="Struct" type="Originator_1"/>
      <BDA name="ctlNum" bType="INT8U"/>
      <BDA name="T" bType="Timestamp"/>
      <BDA name="Test" bType="BOOLEAN"/>
      <BDA name="Check" bType="Check"/>
    </DAType>
    <DAType id="OperEnum_1">
      <BDA name="ctlVal" bType="Enum" type="BehaviourModeKind"/>
      <BDA name="origin" bType="Struct" type="Originator_1"/>
      <BDA name="ctlNum" bType="INT8U"/>
      <BDA name="T" bType="Timestamp"/>
      <BDA name="Test" bType="BOOLEAN"/>
      <BDA name="Check" bType="Check"/>
    </DAType>
    <DAType id="OperEnum_2">
      <BDA name="ctlVal" bType="Enum" type="DERStateTransitionKind"/>
      <BDA name="origin" bType="Struct" type="Originator_1"/>
      <BDA name="ctlNum" bType="INT8U"/>
      <BDA name="T" bType="Timestamp"/>
      <BDA name="Test" bType="BOOLEAN"/>
      <BDA name="Check" bType="Check"/>
    </DAType>
    <DAType id="OperINT32_1">
      <BDA name="ctlVal" bType="INT32"/>
      <BDA name="origin" bType="Struct" type="Originator_1"/>
      <BDA name="ctlNum" bType="INT8U"/>
      <BDA name="T" bType="Timestamp"/>
      <BDA name="Test" bType="BOOLEAN"/>
      <BDA name="Check" bType="Check"/>
    </DAType>
    <DAType id="Originator_1">
      <BDA name="orCat" bType="Enum" type="OriginatorCategoryKind"/>
      <BDA name="orIdent" bType="Octet64"/>
    </DAType>
    <DAType id="Point_1">
      <BDA name="xVal" bType="FLOAT32"/>
      <BDA name="yVal" bType="FLOAT32"/>
    </DAType>
    <DAType id="ScaledValueConfig_1">
      <BDA name="scaleFactor" bType="FLOAT32"/>
      <BDA name="offset" bType="FLOAT32"/>
    </DAType>
    <DAType id="Unit_1">
      <BDA name="SIUnit" bType="Enum" type="SIUnitKind"/>
    </DAType>
    <DAType id="Vector_2">
      <BDA name="mag" bType="Struct" type="AnalogueValue_2"/>
    </DAType>
    <DAType id="Vector_3">
      <BDA name="mag" bType="Struct" type="AnalogueValue_2"/>
      <BDA name="ang" bType="Struct" type="AnalogueValue_2"/>
    </DAType>
    <DAType id="AnalogueValue_1">
      <BDA name="f" bType="FLOAT32"/>
    </DAType>
    <EnumType id="BatteryTypeKind">
      <EnumVal ord="1">Lead-acid</EnumVal>
      <EnumVal ord="2">Nickel-metal hydrate (NiMH)</EnumVal>
      <EnumVal ord="3">Nickel-cadmium (NiCd)</EnumVal>
      <EnumVal ord="5">Carbon zinc</EnumVal>
      <EnumVal ord="4">Lithium ion</EnumVal>
      <EnumVal ord="6">Zinc chloride</EnumVal>
      <EnumVal ord="7">Alkaline</EnumVal>
      <EnumVal ord="8">Rechargeable alkaline</EnumVal>
      <EnumVal ord="9">Sodium sulphur (NaS)</EnumVal>
      <EnumVal ord="10">Flow</EnumVal>
      <EnumVal ord="98">Not applicable or not known</EnumVal>
    </EnumType>
    <EnumType id="BreakerOpCapabilityKind">
      <EnumVal ord="1">None</EnumVal>
      <EnumVal ord="2">Open</EnumVal>
      <EnumVal ord="3">Close-Open</EnumVal>
      <EnumVal ord="4">Open-Close-Open</EnumVal>
      <EnumVal ord="5">Close-Open-Close-Open</EnumVal>
      <EnumVal ord="6">Open-Close-Open-Close-Open</EnumVal>
      <EnumVal ord="7">more</EnumVal>
    </EnumType>
    <EnumType id="CalcIntervalKind">
      <EnumVal ord="1">MS</EnumVal>
      <EnumVal ord="2">PER_CYCLE</EnumVal>
      <EnumVal ord="3">CYCLE</EnumVal>
      <EnumVal ord="4">DAY</EnumVal>
      <EnumVal ord="5">WEEK</EnumVal>
      <EnumVal ord="6">MONTH</EnumVal>
      <EnumVal ord="7">YEAR</EnumVal>
      <EnumVal ord="8">EXTERNAL</EnumVal>
    </EnumType>
    <EnumType id="CalcMethodKind">
      <EnumVal ord="1">UNSPECIFIED</EnumVal>
      <EnumVal ord="2">TRUE_RMS</EnumVal>
      <EnumVal ord="3">PEAK_FUNDAMENTAL</EnumVal>
      <EnumVal ord="4">RMS_FUNDAMENTAL</EnumVal>
      <EnumVal ord="5">MIN</EnumVal>
      <EnumVal ord="6">MAX</EnumVal>
      <EnumVal ord="7">AVG</EnumVal>
      <EnumVal ord="8">SDV</EnumVal>
    </EnumType>
    <EnumType id="CalcModeKind">
      <EnumVal ord="1">TOTAL</EnumVal>
      <EnumVal ord="2">PERIOD</EnumVal>
      <EnumVal ord="3">SLIDING</EnumVal>
    </EnumType>
    <EnumType id="ChargeSourceKind">
      <EnumVal ord="1">Mode A</EnumVal>
      <EnumVal ord="2">Mode B</EnumVal>
      <EnumVal ord="3">Mode C</EnumVal>
    </EnumType>
    <EnumType id="CtlModelKind">
      <EnumVal ord="0">status-only</EnumVal>
      <EnumVal ord="1">direct-with-normal-security</EnumVal>
      <EnumVal ord="2">sbo-with-normal-security</EnumVal>
      <EnumVal ord="3">direct-with-enhanced-security</EnumVal>
      <EnumVal ord="4">sbo-with-enhanced-security</EnumVal>
    </EnumType>
    <EnumType id="CurveCharKind">
      <EnumVal ord="0"/>
      <EnumVal ord="1">ANSI Extremely Inverse</EnumVal>
      <EnumVal ord="2">ANSI Very Inverse</EnumVal>
      <EnumVal ord="4">ANSI Moderate Inverse</EnumVal>
      <EnumVal ord="5">ANSI Definite Time</EnumVal>
      <EnumVal ord="10">IEC Very Inverse</EnumVal>
      <EnumVal ord="11">IEC Inverse</EnumVal>
      <EnumVal ord="12">IEC Extremely Inverse</EnumVal>
      <EnumVal ord="15">IEC Definite Time</EnumVal>
      <EnumVal ord="16">Reserved</EnumVal>
      <EnumVal ord="17">Polynom 1</EnumVal>
      <EnumVal ord="18">Polynom 2</EnumVal>
      <EnumVal ord="19">Polynom 3</EnumVal>
      <EnumVal ord="20">Polynom 4</EnumVal>
      <EnumVal ord="21">Polynom 5</EnumVal>
      <EnumVal ord="22">Polynom 6</EnumVal>
      <EnumVal ord="23">Polynom 7</EnumVal>
      <EnumVal ord="24">Polynom 8</EnumVal>
      <EnumVal ord="25">Polynom 9</EnumVal>
      <EnumVal ord="26">Polynom 10</EnumVal>
      <EnumVal ord="27">Polynom 11</EnumVal>
      <EnumVal ord="28">Polynom 12</EnumVal>
      <EnumVal ord="29">Polynom 13</EnumVal>
      <EnumVal ord="30">Polynom 14</EnumVal>
      <EnumVal ord="31">Polynom 15</EnumVal>
      <EnumVal ord="32">Polynom 16</EnumVal>
      <EnumVal ord="33">Multiline 1</EnumVal>
      <EnumVal ord="34">Multiline 2</EnumVal>
      <EnumVal ord="35">Multiline 3</EnumVal>
      <EnumVal ord="36">Multiline 4</EnumVal>
      <EnumVal ord="37">Multiline 5</EnumVal>
      <EnumVal ord="38">Multiline 6</EnumVal>
      <EnumVal ord="39">Multiline 7</EnumVal>
      <EnumVal ord="40">Multiline 8</EnumVal>
      <EnumVal ord="41">Multiline 9</EnumVal>
      <EnumVal ord="42">Multiline 10</EnumVal>
      <EnumVal ord="43">Multiline 11</EnumVal>
      <EnumVal ord="44">Multiline 12</EnumVal>
      <EnumVal ord="45">Multiline 13</EnumVal>
      <EnumVal ord="46">Multiline 14</EnumVal>
      <EnumVal ord="47">Multiline 15</EnumVal>
      <EnumVal ord="48">Multiline 16</EnumVal>
    </EnumType>
    <EnumType id="DERStateKind">
      <EnumVal ord="1">on but disconnected and not ready</EnumVal>
      <EnumVal ord="2">starting up</EnumVal>
      <EnumVal ord="3">disconnected and available</EnumVal>
      <EnumVal ord="4">disconnected and authorized</EnumVal>
      <EnumVal ord="5">synchronizing</EnumVal>
      <EnumVal ord="6">running</EnumVal>
      <EnumVal ord="7">stopping and disconnecting under emergency conditions</EnumVal>
      <EnumVal ord="8">stopping</EnumVal>
      <EnumVal ord="9">disconnected and blocked</EnumVal>
      <EnumVal ord="10">disconnected and in maintenance</EnumVal>
      <EnumVal ord="11">failed</EnumVal>
      <EnumVal ord="98">Not applicable or not known</EnumVal>
    </EnumType>
    <EnumType id="DERStateTransitionKind">
      <EnumVal ord="1">Start</EnumVal>
      <EnumVal ord="2">Connect</EnumVal>
      <EnumVal ord="3">Disconnect</EnumVal>
      <EnumVal ord="4">Disconnect under emergency conditions</EnumVal>
      <EnumVal ord="5">Get blocked</EnumVal>
      <EnumVal ord="6">Get unblocked</EnumVal>
      <EnumVal ord="7">Go to maintenance</EnumVal>
      <EnumVal ord="8">Go out of maintenance</EnumVal>
      <EnumVal ord="9">Stop</EnumVal>
      <EnumVal ord="10">Turn off controller</EnumVal>
    </EnumType>
    <EnumType id="DERUnitKind">
      <EnumVal ord="1">Diesel / gas engine</EnumVal>
      <EnumVal ord="2">Gas Turbine engine</EnumVal>
      <EnumVal ord="3">PV</EnumVal>
      <EnumVal ord="4">PV plus Storage</EnumVal>
      <EnumVal ord="5">Lithium Ion Battery Storage</EnumVal>
      <EnumVal ord="6">Fuel cell</EnumVal>
      <EnumVal ord="7">Hydro generator</EnumVal>
      <EnumVal ord="8">Wind turbine</EnumVal>
      <EnumVal ord="9">Flow battery storage</EnumVal>
      <EnumVal ord="10">Air compression storage</EnumVal>
      <EnumVal ord="11">Flywheel storage</EnumVal>
      <EnumVal ord="12">Capacitor storage</EnumVal>
      <EnumVal ord="13">Vehicle-to-Grid (V2G)</EnumVal>
      <EnumVal ord="50">Mixed, hybrid DER</EnumVal>
      <EnumVal ord="98">Not applicable or not known</EnumVal>
    </EnumType>
    <EnumType id="DirectionModeKind">
      <EnumVal ord="1">NonDirectional</EnumVal>
      <EnumVal ord="2">Forward</EnumVal>
      <EnumVal ord="3">Reverse</EnumVal>
    </EnumType>
    <EnumType id="ECPConnKind">
      <EnumVal ord="1">PoC: Electric point positioned at the connection of the DER to its local EPS</EnumVal>
      <EnumVal ord="2">IntDER: Electric point positioned internally to the DER</EnumVal>
      <EnumVal ord="3">PCC: Electric point positioned at the connection of local EPS to area EPS - the EPS contains DERs including local loads</EnumVal>
      <EnumVal ord="4">PCCD: specific PCC when the EPS contains only DERs with no loads</EnumVal>
      <EnumVal ord="5">PoCoL: Electric point positioned at the connection of load within the DER local EPS</EnumVal>
      <EnumVal ord="6">ExtPCC: Electric point positioned at the connection to a PCC external to the area EPS</EnumVal>
      <EnumVal ord="7">ExtPoC: Electric point positioned at the connection of DER within local EPS outside of the DER local EPS</EnumVal>
      <EnumVal ord="8">AuxLoad: Connection of auxilliary load to DER</EnumVal>
      <EnumVal ord="9">PoCG: Connection of group of possibly different types of DERs to local EPS</EnumVal>
      <EnumVal ord="98">Not applicable or not known</EnumVal>
    </EnumType>
    <EnumType id="ECPIslandStateKind">
      <EnumVal ord="1">Factory configuration (from vendor)</EnumVal>
      <EnumVal ord="2">Default configuration (after installation)</EnumVal>
      <EnumVal ord="3">Normal grid-connected configuration</EnumVal>
      <EnumVal ord="4">Islanded condition 1 (local island behind the PCC)</EnumVal>
      <EnumVal ord="5">Islanded condition 2 (islanded at PCC)</EnumVal>
      <EnumVal ord="6">Islanded condition 3 (multiple PCC regional island)</EnumVal>
      <EnumVal ord="7">1st Alternate grid-connected configuration</EnumVal>
      <EnumVal ord="8">2nd Alternate grid-connected configuration</EnumVal>
      <EnumVal ord="9">3rd Alternate grid-connected configuration</EnumVal>
      <EnumVal ord="98">Not applicable or not known</EnumVal>
    </EnumType>
    <EnumType id="EquipmentTestResultKind">
      <EnumVal ord="1">unavailable</EnumVal>
      <EnumVal ord="2">success</EnumVal>
      <EnumVal ord="3">fault (bad)</EnumVal>
      <EnumVal ord="4">test running</EnumVal>
      <EnumVal ord="5">test aborted</EnumVal>
      <EnumVal ord="98">Not applicable or not known</EnumVal>
    </EnumType>
    <EnumType id="FaultDirectionKind">
      <EnumVal ord="0">unknown</EnumVal>
      <EnumVal ord="1">forward</EnumVal>
      <EnumVal ord="2">backward</EnumVal>
      <EnumVal ord="3">both</EnumVal>
    </EnumType>
    <EnumType id="GroundingSystemKind">
      <EnumVal ord="1">IT</EnumVal>
      <EnumVal ord="2">TN-S</EnumVal>
      <EnumVal ord="3">TN-C</EnumVal>
      <EnumVal ord="4">TN-C-S</EnumVal>
      <EnumVal ord="5">TT</EnumVal>
    </EnumType>
    <EnumType id="HealthKind">
      <EnumVal ord="1">Ok</EnumVal>
      <EnumVal ord="2">Warning</EnumVal>
      <EnumVal ord="3">Alarm</EnumVal>
    </EnumType>
    <EnumType id="OriginatorCategoryKind">
      <EnumVal ord="0">not-supported</EnumVal>
      <EnumVal ord="1">bay-control</EnumVal>
      <EnumVal ord="2">station-control</EnumVal>
      <EnumVal ord="3">remote-control</EnumVal>
      <EnumVal ord="4">automatic-bay</EnumVal>
      <EnumVal ord="5">automatic-station</EnumVal>
      <EnumVal ord="6">automatic-remote</EnumVal>
      <EnumVal ord="7">maintenance</EnumVal>
      <EnumVal ord="8">process</EnumVal>
    </EnumType>
    <EnumType id="PFSignKind">
      <EnumVal ord="1">IEC</EnumVal>
      <EnumVal ord="2">EEI</EnumVal>
    </EnumType>
    <EnumType id="POWSwitchingCapabilityKind">
      <EnumVal ord="1">None</EnumVal>
      <EnumVal ord="2">Close</EnumVal>
      <EnumVal ord="3">Open</EnumVal>
      <EnumVal ord="4">Close and Open</EnumVal>
    </EnumType>
    <EnumType id="PhaseKind">
      <EnumVal ord="1">Single phase to neutral</EnumVal>
      <EnumVal ord="2">Split phase</EnumVal>
      <EnumVal ord="3">2-phase</EnumVal>
      <EnumVal ord="4">3-phase delta</EnumVal>
      <EnumVal ord="5">3-phase wye / 4-wires</EnumVal>
      <EnumVal ord="6">3-phase wye / 5-wires</EnumVal>
      <EnumVal ord="9">DC</EnumVal>
      <EnumVal ord="98">Not applicable or not known</EnumVal>
    </EnumType>
    <EnumType id="ResetCurveKind">
      <EnumVal ord="1">None</EnumVal>
      <EnumVal ord="2">Definite Time Delayed Reset</EnumVal>
      <EnumVal ord="3">Inverse Reset</EnumVal>
    </EnumType>
    <EnumType id="SIUnitKind">
      <EnumVal ord="1"/>
      <EnumVal ord="2">m</EnumVal>
      <EnumVal ord="3">kg</EnumVal>
      <EnumVal ord="4">s</EnumVal>
      <EnumVal ord="5">A</EnumVal>
      <EnumVal ord="6">K</EnumVal>
      <EnumVal ord="7">mol</EnumVal>
      <EnumVal ord="8">cd</EnumVal>
      <EnumVal ord="9">deg</EnumVal>
      <EnumVal ord="10">rad</EnumVal>
      <EnumVal ord="11">sr</EnumVal>
      <EnumVal ord="21">Gy</EnumVal>
      <EnumVal ord="22">Bq</EnumVal>
      <EnumVal ord="23">°C</EnumVal>
      <EnumVal ord="24">Sv</EnumVal>
      <EnumVal ord="25">F</EnumVal>
      <EnumVal ord="26">C</EnumVal>
      <EnumVal ord="27">S</EnumVal>
      <EnumVal ord="28">H</EnumVal>
      <EnumVal ord="29">V</EnumVal>
      <EnumVal ord="30">ohm</EnumVal>
      <EnumVal ord="31">J</EnumVal>
      <EnumVal ord="32">N</EnumVal>
      <EnumVal ord="33">Hz</EnumVal>
      <EnumVal ord="34">lx</EnumVal>
      <EnumVal ord="35">Lm</EnumVal>
      <EnumVal ord="36">Wb</EnumVal>
      <EnumVal ord="37">T</EnumVal>
      <EnumVal ord="38">W</EnumVal>
      <EnumVal ord="39">Pa</EnumVal>
      <EnumVal ord="41">m²</EnumVal>
      <EnumVal ord="42">m³</EnumVal>
      <EnumVal ord="43">m/s</EnumVal>
      <EnumVal ord="44">m/s²</EnumVal>
      <EnumVal ord="45">m³/s</EnumVal>
      <EnumVal ord="46">m/m³</EnumVal>
      <EnumVal ord="47">M</EnumVal>
      <EnumVal ord="48">kg/m³</EnumVal>
      <EnumVal ord="49">m²/s</EnumVal>
      <EnumVal ord="50">W/m K</EnumVal>
      <EnumVal ord="51">J/K</EnumVal>
      <EnumVal ord="52">ppm</EnumVal>
      <EnumVal ord="53">1/s</EnumVal>
      <EnumVal ord="54">rad/s</EnumVal>
      <EnumVal ord="61">VA</EnumVal>
      <EnumVal ord="63">VAr</EnumVal>
      <EnumVal ord="64">phi</EnumVal>
      <EnumVal ord="65">cos(phi)</EnumVal>
      <EnumVal ord="66">Vs</EnumVal>
      <EnumVal ord="67">V²</EnumVal>
      <EnumVal ord="68">As</EnumVal>
      <EnumVal ord="69">A²</EnumVal>
      <EnumVal ord="70">A²t</EnumVal>
      <EnumVal ord="71">VAh</EnumVal>
      <EnumVal ord="72">Wh</EnumVal>
      <EnumVal ord="73">VArh</EnumVal>
      <EnumVal ord="74">V/Hz</EnumVal>
      <EnumVal ord="75">Hz/s</EnumVal>
      <EnumVal ord="76">char</EnumVal>
      <EnumVal ord="77">char/s</EnumVal>
      <EnumVal ord="78">kgm²</EnumVal>
      <EnumVal ord="79">dB</EnumVal>
      <EnumVal ord="80">J/Wh</EnumVal>
      <EnumVal ord="81">W/s</EnumVal>
      <EnumVal ord="82">l/s</EnumVal>
      <EnumVal ord="83">dBm</EnumVal>
      <EnumVal ord="84">h</EnumVal>
      <EnumVal ord="85">min</EnumVal>
      <EnumVal ord="86">Ohm/m</EnumVal>
      <EnumVal ord="87">percent/s</EnumVal>
      <EnumVal ord="88">A/V</EnumVal>
      <EnumVal ord="89">A/Vs</EnumVal>
    </EnumType>
    <EnumType id="BehaviourModeKind">
      <EnumVal ord="1">on</EnumVal>
      <EnumVal ord="2">blocked</EnumVal>
      <EnumVal ord="3">test</EnumVal>
      <EnumVal ord="4">test/blocked</EnumVal>
      <EnumVal ord="5">off</EnumVal>
    </EnumType>
    <EnumType id="BatteryChargerChargingModeStatusKind">
      <EnumVal ord="0">Not applicable or not known</EnumVal>
      <EnumVal ord="1">Off</EnumVal>
      <EnumVal ord="2">Operational mode</EnumVal>
      <EnumVal ord="3">Test mode</EnumVal>
      <EnumVal ord="99">Other</EnumVal>
    </EnumType>
    <EnumType id="STotalCalcMethodKind">
      <EnumVal ord="1">Vector</EnumVal>
      <EnumVal ord="2">Arithmetic</EnumVal>
    </EnumType>
    <EnumType id="SwitchTypeKind">
      <EnumVal ord="1">Load Break</EnumVal>
      <EnumVal ord="2">Disconnector</EnumVal>
      <EnumVal ord="3">Earthing Switch</EnumVal>
      <EnumVal ord="4">High Speed Earthing Switch</EnumVal>
    </EnumType>
    <EnumType id="SwitchingCapabilityKind">
      <EnumVal ord="1">None</EnumVal>
      <EnumVal ord="2">Open</EnumVal>
      <EnumVal ord="3">Close</EnumVal>
      <EnumVal ord="4">Open and Close</EnumVal>
    </EnumType>
    <EnumType id="BatteryChargerModeSettingKind">
      <EnumVal ord="0">not applicable or not known</EnumVal>
      <EnumVal ord="1">off</EnumVal>
      <EnumVal ord="2">Operational mode</EnumVal>
      <EnumVal ord="3">Test mode</EnumVal>
      <EnumVal ord="99">Other</EnumVal>
    </EnumType>
  </DataTypeTemplates>
</SCL>
