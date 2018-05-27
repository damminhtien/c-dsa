using Microsoft.ProjectOxford.Face;
using Microsoft.ProjectOxford.Face.Contract;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AI_face
{
    class Program
    {
        FaceServiceClient faceServiceClient = new FaceServiceClient("6ffdefcceda4407aa5881f1e23862517","https://westcentralus.api.cognitive.microsoft.com/face/v1.0");

        private async void CreatePersonGroup(string personGroupId, string personGroupName)
        {
            try
            {
                await faceServiceClient.CreatePersonGroupAsync(personGroupId, personGroupName);
            }
            catch (Exception e)
            {
                Console.WriteLine("Create person group error: \n" + e.Message);
            }
        }

        private async void AddPersonToGroup(string personGroupId, string name, string pathImg)
        {
            try
            {
                await faceServiceClient.GetPersonGroupAsync(personGroupId);
                CreatePersonResult person = await faceServiceClient.CreatePersonAsync(personGroupId, name);

                DetectFaceAndRegister(personGroupId, person, pathImg);
            }
            catch (Exception e)
            {
                Console.WriteLine("Add person group error: \n" + e.Message);
            }
        }

        private async void DetectFaceAndRegister(string personGroupId, CreatePersonResult person, string pathImg)
        {
            foreach (var img in Directory.GetFiles(pathImg, "*.JPG"))
            {
                using (Stream s = File.OpenRead(img))
                {
                    await faceServiceClient.AddPersonFaceAsync(personGroupId, person.PersonId, s);
                }
            }
        }

        public async void TrainingAI(string personGroupId)
        {
            await faceServiceClient.TrainPersonGroupAsync(personGroupId);
            TrainingStatus trainingStatus = null;
            while (true)
            {
                trainingStatus = await faceServiceClient.GetPersonGroupTrainingStatusAsync(personGroupId);
                if (trainingStatus.Status != Status.Running)
                    break;
                await Task.Delay(1000);
            }
            Console.WriteLine("Training AI successfull");
        }

        public async void RecognitionFace(string personGroupId, string imgPath)
        {
            using (Stream s = File.OpenRead(imgPath))
            {
                var faces = await faceServiceClient.DetectAsync(s);
                var faceIds = faces.Select(face => face.FaceId).ToArray();

                try
                {
                    var results = await faceServiceClient.IdentifyAsync(personGroupId, faceIds);
                    foreach(var identifyResult in results)
                    {
                        Console.WriteLine($"Result of face: {identifyResult.FaceId}");
                        if(identifyResult.Candidates.Length == 0)
                            Console.WriteLine("No one identify");
                        else 
                        {
                            var candidateId = identifyResult.Candidates[0].PersonId;
                            var person = await faceServiceClient.GetPersonAsync(personGroupId, candidateId);
                            Console.WriteLine($"Identify as {person.Name}");
                        }
                    }
                }
                catch(Exception e)
                {
                    Console.WriteLine("Error Recognition Face: " + e.Message);
                }
            }
        }

        static void Main(string[] args)
        {
            //new Program().CreatePersonGroup("mylove", "My Love <3");
            //new Program().AddPersonToGroup("mylove", "Dam Minh Tien", @"E:\ImgTraining\DMT\");
            //new Program().AddPersonToGroup("mylove", "Nguyen Thi Huyen", @"E:\ImgTraining\Crush\");
            //new Program().AddPersonToGroup("mylove", "Vuong Quynh Huong", @"E:\ImgTraining\Huong\");
            //new Program().AddPersonToGroup("mylove", "Tran Trong Binh", @"E:\ImgTraining\Binh\");
            //new Program().AddPersonToGroup("mylove", "Ngo Thuy Hoa", @"E:\ImgTraining\Hoa\");
            //new Program().TrainingAI("mylove");
            new Program().RecognitionFace("mylove",@"E:\ImgTraining\TestFace\3.JPG");
            Console.ReadLine();
        }
    }
}
