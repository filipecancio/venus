#include <pgmspace.h>

#define SECRET

const char ssid[] = "redewifi";
const char pass[] = "senha";

#define THINGNAME "thing id"

int8_t TIME_ZONE = -3;

const char MQTT_HOST[] = "eugenioprod-iothub.azure-devices.net";
const char MQTT_USER[] = "eugenioprod-iothub.azure-devices.net/" THINGNAME "/api-version=2017-06-30";
const int MQTT_PORT = 8883;
const char MQTT_SUB_TOPIC[] = "$iothub/methods/POST/#";
const char MQTT_PUB_TOPIC[] = "devices/" THINGNAME "/messages/events/";


// Copie aqui o seu certificado CA do EUGENIO (ex: CAxxxxx.pem) ▼
static const char cacert[] PROGMEM = \
"-----BEGIN CERTIFICATE-----\n"\
"MIIDdzCCAl+gAwIBAgIEAgAAuTANBgkqhkiG9w0BAQUFADBaMQswCQYDVQQGEwJJ\n"\
"RTESMBAGA1UEChMJQmFsdGltb3JlMRMwEQYDVQQLEwpDeWJlclRydXN0MSIwIAYD\n"\
"VQQDExlCYWx0aW1vcmUgQ3liZXJUcnVzdCBSb290MB4XDTAwMDUxMjE4NDYwMFoX\n"\
"DTI1MDUxMjIzNTkwMFowWjELMAkGA1UEBhMCSUUxEjAQBgNVBAoTCUJhbHRpbW9y\n"\
"ZTETMBEGA1UECxMKQ3liZXJUcnVzdDEiMCAGA1UEAxMZQmFsdGltb3JlIEN5YmVy\n"\
"VHJ1c3QgUm9vdDCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAKMEuyKr\n"\
"mD1X6CZymrV51Cni4eiVgLGw41uOKymaZN+hXe2wCQVt2yguzmKiYv60iNoS6zjr\n"\
"IZ3AQSsBUnuId9Mcj8e6uYi1agnnc+gRQKfRzMpijS3ljwumUNKoUMMo6vWrJYeK\n"\
"mpYcqWe4PwzV9/lSEy/CG9VwcPCPwBLKBsua4dnKM3p31vjsufFoREJIE9LAwqSu\n"\
"XmD+tqYF/LTdB1kC1FkYmGP1pWPgkAx9XbIGevOF6uvUA65ehD5f/xXtabz5OTZy\n"\
"dc93Uk3zyZAsuT3lySNTPx8kmCFcB5kpvcY67Oduhjprl3RjM71oGDHweI12v/ye\n"\
"jl0qhqdNkNwnGjkCAwEAAaNFMEMwHQYDVR0OBBYEFOWdWTCCR1jMrPoIVDaGezq1\n"\
"BE3wMBIGA1UdEwEB/wQIMAYBAf8CAQMwDgYDVR0PAQH/BAQDAgEGMA0GCSqGSIb3\n"\
"DQEBBQUAA4IBAQCFDF2O5G9RaEIFoN27TyclhAO992T9Ldcw46QQF+vaKSm2eT92\n"\
"9hkTI7gQCvlYpNRhcL0EYWoSihfVCr3FvDB81ukMJY2GQE/szKN+OMY3EU/t3Wgx\n"\
"jkzSswF07r51XgdIGn9w/xZchMB5hbgF/X++ZRGjD8ACtPhSNzkE1akxehi/oCr0\n"\
"Epn3o0WC4zxe9Z2etciefC7IpJ5OCBRLbf1wbWsaY71k5h+3zvDyny67G7fyUIhz\n"\
"ksLi4xaNmjICq44Y3ekQEe5+NauQrz4wlHrQMz2nZQ/1/I6eYs9HRCwBXbsdtTLS\n"\
"R9I4LtD+gdwyah617jzV/OeBHRnDJELqYzmp\n"\
"-----END CERTIFICATE-----\n";


// Copie aqui o seu certificar do cliente do EUGENIO (ex: xxxxx.pem) ▼
static const char client_cert[] PROGMEM = \
"-----BEGIN CERTIFICATE-----\n"\
"MIIFCTCCAvGgAwIBAgIUN4Nl0YCpH0vEaWyn4NlwnYSw/qIwDQYJKoZIhvcNAQEL\n"\
"BQAwFDESMBAGA1UEAwwJbG9jYWxob3N0MB4XDTIwMTAwNDAxNDg1NFoXDTIxMTAw\n"\
"NDAxNDg1NFowFDESMBAGA1UEAwwJbG9jYWxob3N0MIICIjANBgkqhkiG9w0BAQEF\n"\
"AAOCAg8AMIICCgKCAgEAvYWVL4fM2rKNdHuTD0Ng53N6oO7p+CdKw+gTHOAspolI\n"\
"py1Et81ZsKBW4M+vJewV231r/OFDZH7U3p0TLv9leHwiNVz3nGzRdvO2bNhq5PDa\n"\
"+QDsbhmT1ppxknNkdixflEtCj74AwpJPH+tM2k/cwao2DtbguR3Toc0ZFh6PXx9V\n"\
"hgb0LElgZ8WdhTtBQAKDSkYnFwP/4o8vBT0e0/1U40fXjpHUieqKsNatzgVgV3nt\n"\
"rcMGNFLrJ8KiUgm6jZOJ/Uc2Y9RC4rbjhJZkllxlI/AJovLndYJ/eYwaALAd8G/F\n"\
"Glps4zUPY8WVoAxPzNg2Bt36GwVkWH3P18gboUm5v2rH66AjBcQOg4bpNb85DnMT\n"\
"jnN13A3nJm/xtlt1FHjuGtwLGYqKzAoG63PdTqPd3kSDHkiNEr7EommyED83MA+f\n"\
"GRhqY1Lt1g2TlTvwis1evP9S5gBXBefs/UwQdozhIYEtT/Sl9qTssTUOZqrN1jJv\n"\
"k6akoWh+XRZGONWSWlmQmEkxXs7RHjOmX8y3xdK4KnDN1IGGF1zaBurycIoppvgw\n"\
"tw//yIrptiDkBScJlSUHHgC8HGTrWH/Weh3GfCoZaBs0C9OS8hi/yGJPrVRiPmae\n"\
"uotmC75lYfn9Q4KsXOl4ZMxRCcqpwajZa1/p1RAcP5sOn3nMC1w4k3gNtyKOQPEC\n"\
"AwEAAaNTMFEwHQYDVR0OBBYEFB1YpYRjgJgyNkfnj0pIQMP0L3fNMB8GA1UdIwQY\n"\
"MBaAFB1YpYRjgJgyNkfnj0pIQMP0L3fNMA8GA1UdEwEB/wQFMAMBAf8wDQYJKoZI\n"\
"hvcNAQELBQADggIBALgj+wHdiuNYBlx3K0ZBvFBRrXGeV8GP/zLpZV6FXDVP6WiJ\n"\
"lShNn7uJinYLx+wcDMb+ffKmgLJnryfYJuFnTsmCVdJSt6oEhB+tv/eNGKBDXTze\n"\
"RU0fIj259B9iUEujqjLMcidKxVocIKknred+E7Wkf/m233qJAaUG+UBFQqWAg6jw\n"\
"s5SCTBkcDyKr85RuNyvlJAZuhP6uDEHYfVV66dgnDqf+K1/AbvsOhak2jYb2BRKt\n"\
"Wg16cFhHSrYOusgbXt6hEQCFLGuKCLp+mDsCRGHToM9drRDiFSHsDMzl3xFXAHhL\n"\
"RVi4U4gjl6RmYSl9FdXxkpJepU/cX4URwsza+ReXxNyWdqytLTmNfZ9iSz6KF6RC\n"\
"xZ2m0x9JljyK2iB38RHiC0AnEMaBAJJYQZXDNN5DMMM4VCGFYB0ITC+jXKffYVhU\n"\
"fWFsYiLH9l1HZk+cHHPZZUqn83uj2gIC1q8V2GJ5uDj5C9bAgQFFfrjagTXOaSjC\n"\
"9wDemc6I9m7WeMwEDWoY/88Q7mJRZM3UJwqPjyEeOSmnTBL96uh1qkf4KACBlMlb\n"\
"w4QUzPV43dluasxaU/BUV8fxksTpGUuQ0Mff3Gq/WjyFXAyW3dvGMpvyhWgNZrKr\n"\
"47HB3sOE5d0S+6Fq3SLyjsE72T87VkG+2UVSw9zPAw29sX7/8y+mWbC71U09\n"\
"-----END CERTIFICATE-----\n";

// Copie aqui a sua chave privada do certificado do cleinte do EUGENIO (ex: xxxxx.key.pem) ▼
static const char privkey[] PROGMEM = \
"-----BEGIN PRIVATE KEY-----\n"\
"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\n"\
"JL0pL76m8GG0gbR3n5TJaKxSTr1hJTfP\n"\
"-----END PRIVATE KEY-----\n";