require "fileutils"

# == Schema Information
#
# Table name: projects
#
#  id          :integer          not null, primary key
#  path        :string
#  name        :string
#  owner_id    :integer
#  description :text
#  created_at  :datetime         not null
#  updated_at  :datetime         not null
#

class Project < ActiveRecord::Base
  def create
    begin
      FileUtils.mkdir_p(self.path, :mode => 0775)
      FileUtils.cd(self.path)
      FileUtils.mkdir(["Data", "Flows"], :mode => 0775)
    rescue
      # TODO: add error handling
      puts "Project directory #{self.path} cannot be created"
    end
  end
end
